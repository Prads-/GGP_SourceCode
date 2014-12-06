#include <iostream>
#include "SymbolTable.h"
#include "Exception.h"
#include "TokenType.h"

SymbolTable::~SymbolTable() {
	for (STable::iterator it = table.begin(); it != table.end(); ++it) {
		delete it->second;
	}
}

void SymbolTable::addSymbols(const std::vector<GDLNode*> &ast) {
	for (const GDLNode *node : ast) {
		switch (node->getInstanceOf()) {
			case INSTANCE_OF_ROLE_NODE:
				addRole((RoleNode*)node);
				break;
			case INSTANCE_OF_RELATION_NODE:
				addRelation((RelationNode*)node);
				break;
			case INSTANCE_OF_IF_NODE:
				processIfNode((IfNode*)node);
				break;
			case INSTANCE_OF_BASE_NODE:
				processBaseNode((BaseNode*)node);
				break;
			case INSTANCE_OF_INIT_NODE:
				processInitNode((InitNode*)node);
				break;
			case INSTANCE_OF_INPUT_NODE:
				processInputNode((InputNode*)node);
				break;
			default:
				throw Exception("Unexpected node type in the abstract syntax tree");
		}
	}
}

void SymbolTable::addRole(const RoleNode *roleNode) {
	const Token t = roleNode->getRole();
	
	if (t.getType() != TOKENIZER_TOKEN_TYPE_TERM) {
		throw Exception("Unexpected type in role node");
	}
	
	std::string role = t.getTokenStr();
	for (const std::string &r : roles) {
		if (r == role) {
			return;
		}
	}
	roles.push_back(role);
}

void SymbolTable::addRelation(const RelationNode *relationNode) {
	const std::vector<Token> arguments = relationNode->getArguments();
	
	for (const Token &token : arguments) {
		if (token.getType() != TOKENIZER_TOKEN_TYPE_TERM) {
			throw Exception("Unexpected type in relation node");
		}
	}
	
	std::string name = relationNode->getName();
	STable::iterator it = table.find(name);
	Symbol *symbol;
	if (it == table.end()) {
		symbol = new Symbol(name, SYMBOL_TYPE_RELATION, relationNode->getArguments().size());
		std::pair<std::string, Symbol*> entry(name, symbol);
		table.insert(entry);
	} else {
		symbol = it->second;
		if (symbol->getNumOfArgument() != relationNode->getArguments().size()) {
			throw Exception("Different number of argument in same relation: " + name);
		}
	}
	for (size_t i = 0; i < relationNode->getArguments().size(); ++i) {
		symbol->addArgument(i, relationNode->getArguments()[i].getTokenStr());
	}
}

void SymbolTable::addProposition(const PropositionNode *propositionNode, bool isRule) {
	std::string name = propositionNode->getName();
	STable::iterator it = table.find(name);
	
	Symbol *symbol;
	if (it != table.end()) {
		symbol = it->second;
		if (symbol->getType() == SYMBOL_TYPE_RELATION) {
			if (isRule) {
				throw Exception("Relation cannot be in the head of if node: " + name);
			} else {
				return;
			}
		} else if (symbol->getType() == SYMBOL_TYPE_PROPOSITION && isRule) {
			symbol->setType(SYMBOL_TYPE_RULE);
		}
		if (symbol->getNumOfArgument() != propositionNode->getArguments().size()) {
			throw Exception(std::string("Different number of arguments in same") + std::string(((isRule) ? "rule" : "proposition")) + std::string(": ") + name);
		}
	} else {
		symbol = new Symbol(name, ((isRule) ? SYMBOL_TYPE_RULE : SYMBOL_TYPE_PROPOSITION), propositionNode->getArguments().size());
		std::pair<std::string, Symbol*> entry(name, symbol);
		table.insert(entry);
	}
	for (size_t i = 0; i < propositionNode->getArguments().size(); ++i) {
		if (propositionNode->getArguments()[i].getType() == TOKENIZER_TOKEN_TYPE_TERM) {
			std::string argument = propositionNode->getArguments()[i].getTokenStr();
			if (!argumentExists(symbol->getArgumentDomain(i), argument)) {
				symbol->addArgument(i, argument);
			}
		}
	}
}

void SymbolTable::addAction(const PropositionNode *action) {
	std::string name = action->getName();
	STable::iterator it = table.find(name);
	
	Symbol *symbol;
	if (it != table.end()) {
		symbol = it->second;
		if (symbol->getType() != SYMBOL_TYPE_ACTION) {
			throw Exception("Action is already in the table with differnet type: " + name);
		}
		if (symbol->getNumOfArgument() != action->getArguments().size()) {
			throw Exception("Different number of arguments in same action: " + name);
		}
	} else {
		symbol = new Symbol(name, SYMBOL_TYPE_ACTION, action->getArguments().size());
		std::pair<std::string, Symbol*> entry(name, symbol);
		table.insert(entry);
	}
	for (size_t i = 0; i < action->getArguments().size(); ++i) {
		if (action->getArguments()[i].getType() == TOKENIZER_TOKEN_TYPE_TERM) {
			std::string argument = action->getArguments()[i].getTokenStr();
			if (!argumentExists(symbol->getArgumentDomain(i), argument)) {
				symbol->addArgument(i, argument);
			}
		}
	}
}

void SymbolTable::processIfNode(const IfNode *ifNode) {
	processGDLNode(ifNode->getHead(), true);
	for (const GDLNode *gdlNode : ifNode->getBody()) {
		processGDLNode(gdlNode, false);
	}
}

bool SymbolTable::argumentExists(const std::vector<std::string> &arguments, const std::string &argument) {
	for (const std::string &a : arguments) {
		if (a == argument) {
			return true;
		}
	}
	return false;
}

void SymbolTable::processLegalNode(const LegalNode *legalNode) {
	addAction(legalNode->getAction());
}

void SymbolTable::processTrueNode(const TrueNode *trueNode) {
	addProposition(trueNode->getProposition());
}

void SymbolTable::processNotNode(const NotNode *notNode) {
	addProposition(notNode->getProposition());
}

void SymbolTable::processNextNode(const NextNode *nextNode) {
	addProposition(nextNode->getProposition());
}

void SymbolTable::processOrNode(const OrNode *orNode) {
	for (const PropositionNode *proposition : orNode->getPropositions()) {
		addProposition(proposition);
	}
}

void SymbolTable::processBaseNode(const BaseNode *baseNode) {
	addProposition(baseNode->getProposition());
}

void SymbolTable::processInputNode(const InputNode *inputNode) {
	addAction(inputNode->getAction());
}

void SymbolTable::processDoesNode(const DoesNode *doesNode) {
	addAction(doesNode->getAction());
}

void SymbolTable::processInitNode(const InitNode *initNode) {
	addProposition(initNode->getProposition());
}

void SymbolTable::processGDLNode(const GDLNode *gdlNode, bool isIfHead) {
	switch (gdlNode->getInstanceOf()) {
		case INSTANCE_OF_BASE_NODE:
			if (!isIfHead) {
				throw Exception("Base cannot be in the body of if node");
			}
			processBaseNode((BaseNode*)gdlNode);
			break;
		case INSTANCE_OF_DISTINCT_NODE:
			if (isIfHead) {
				throw Exception("Distinct cannot be in the head of if node");
			}
			break;
		case INSTANCE_OF_DOES_NODE:
			if (isIfHead) {
				throw Exception("Does cannot be in the head of if node");
			}
			processDoesNode((DoesNode*)gdlNode);
			break;
		case INSTANCE_OF_GOAL_NODE:
			if (!isIfHead) {
				throw Exception("Goal cannot be in the body of if node");
			}
			break;
		case INSTANCE_OF_INIT_NODE:
			if (!isIfHead) {
				throw Exception("Init cannot be in the body of if node");
			}
			processInitNode((InitNode*)gdlNode);
			break;
		case INSTANCE_OF_INPUT_NODE:
			if (!isIfHead) {
				throw Exception("Input cannot be in the body of if node");
			}
			processInputNode((InputNode*)gdlNode);
			break;
		case INSTANCE_OF_LEGAL_NODE:
			if (!isIfHead) {
				throw Exception("Legal cannot be in the body of if node");
			}
			processLegalNode((LegalNode*)gdlNode);
			break;
		case INSTANCE_OF_NEXT_NODE:
			if (!isIfHead) {
				throw Exception("Next cannot be in the body of if node");
			}
			processNextNode((NextNode*)gdlNode);
			break;
		case INSTANCE_OF_NOT_NODE:
			if (isIfHead) {
				throw Exception("Not cannot be in the head of if node");
			}
			processNotNode((NotNode*)gdlNode);
			break;
		case INSTANCE_OF_OR_NODE:
			if (isIfHead) {
				throw Exception("Or cannot be in the head of if node");
			}
			processOrNode((OrNode*)gdlNode);
			break;
		case INSTANCE_OF_PROPOSITION_NODE:
			if (isIfHead) {
				addProposition((PropositionNode*)gdlNode, true);
			} else {
				addProposition((PropositionNode*)gdlNode);
			}
			break;
		case INSTANCE_OF_TERMINAL_NODE:
			if (!isIfHead) {
				throw Exception("Terminal cannot be in the body of if node");
			}
			break;
		case INSTANCE_OF_TRUE_NODE:
			if (isIfHead) {
				throw Exception("True cannot be in the head of if node");
			}
			processTrueNode((TrueNode*)gdlNode);
			break;
		case INSTANCE_OF_ROLE_NODE:
			break;
		default:
			throw Exception("processGDLNode function threw an exception: Unexpected Node of type " + std::to_string(gdlNode->getInstanceOf()));
	}
}

void SymbolTable::print() const {
	std::cout << "Roles:" << std::endl;
	for (const std::string &role : roles) {
		std::cout << role << std::endl;
	}
	std::cout << std::endl << "Symbols:" << std::endl;
	for (STable::const_iterator it = table.begin(); it != table.end(); ++it) {
		it->second->print();
	}
}

Symbol *SymbolTable::getSymbol(std::string name) {
	STable::iterator it = table.find(name);
	if (it == table.end()) {
		return 0;
	}
	return it->second;
}

const std::vector<std::string> &SymbolTable::getRoles() const {
	return roles;
}