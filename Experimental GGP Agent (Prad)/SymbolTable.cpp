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
				addRole((const RoleNode*)node);
				break;
			case INSTANCE_OF_RELATION_NODE:
				addRelation((const RelationNode*)node);
				break;
			case INSTANCE_OF_IF_NODE:
				checkIfNode((const IfNode*)node);
				break;
			case INSTANCE_OF_INIT_NODE:
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
	
	std::string name = "";// = relationNode->getName();
	STable::iterator it = table.find(name);
	Symbol *symbol;
	if (it == table.end()) {
		symbol = new Symbol(name, SYMBOL_TYPE_RELATION, relationNode->getArguments().size());
		std::pair<std::string, Symbol*> entry(name, symbol);
		table.insert(entry);
	} else {
		symbol = it->second;
		if (symbol->getNumOfArgument() != relationNode->getArguments().size()) {
			throw Exception("Unmatched number of argument in relation " + name);
		}
	}
	for (size_t i = 0; i < relationNode->getArguments().size(); ++i) {
		symbol->addArgument(i, relationNode->getArguments()[i].getTokenStr());
	}
}

void SymbolTable::addProposition(const PropositionNode *propositionNode) {
	std::string name = propositionNode->getName();
	STable::iterator it = table.find(name);
	
	Symbol *symbol;
	if (it != table.end()) {
		if (it->second->getType() == SYMBOL_TYPE_RELATION) {
			return;
		}
		symbol = it->second;
		if (symbol->getNumOfArgument() != propositionNode->getArguments().size()) {
			throw Exception("Unmatched number of argument in proposition " + name);
		}
	} else {
		symbol = new Symbol(name, SYMBOL_TYPE_PROPOSITION, propositionNode->getArguments().size());
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

void SymbolTable::checkIfNode(const IfNode *ifNode) {
	
}

bool SymbolTable::argumentExists(const std::vector<std::string> &arguments, const std::string &argument) {
	for (const std::string &a : arguments) {
		if (a == argument) {
			return true;
		}
	}
	return false;
}