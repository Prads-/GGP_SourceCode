#include <stdexcept>
#include "Exception.h"
#include "GDLNode.h"
#include "TokenLineType.h"
#include "TokenLiner.h"
#include "TokenType.h"
#include "BaseNode.h"
#include "DistinctNode.h"
#include "DoesNode.h"
#include "GoalNode.h"
#include "IfNode.h"
#include "InitNode.h"
#include "InputNode.h"
#include "LegalNode.h"
#include "NextNode.h"
#include "NotNode.h"
#include "OrNode.h"
#include "PropositionNode.h"
#include "TerminalNode.h"
#include "TrueNode.h"
#include "RelationNode.h"
#include "RoleNode.h"

GDLNode *GDLNode::createGDLNodes(const TokenLine &tokenLine) {
	GDLNode *node = 0;
	switch (tokenLine.getType()) {
		case TOKEN_LINE_BASE:
			createBaseNode(tokenLine, &node);
			break;
		case TOKEN_LINE_DISTINCT:
			createDistinctNode(tokenLine, &node);
			break;
		case TOKEN_LINE_DOES:
			createDoesNode(tokenLine, &node);
			break;
		case TOKEN_LINE_GOAL:
			createGoalNode(tokenLine, &node);
			break;
		case TOKEN_LINE_IF:
			createIfNode(tokenLine, &node);
			break;
		case TOKEN_LINE_INIT:
			createInitNode(tokenLine, &node);
			break;
		case TOKEN_LINE_INPUT:
			createInputNode(tokenLine, &node);
			break;
		case TOKEN_LINE_LEGAL:
			createLegalNode(tokenLine, &node);
			break;
		case TOKEN_LINE_NEXT:
			createNextNode(tokenLine, &node);
			break;
		case TOKEN_LINE_NOT:
			createNotNode(tokenLine, &node);
			break;
		case TOKEN_LINE_OR:
			createOrNode(tokenLine, &node);
			break;
		case TOKEN_LINE_RELATION:
			createPropositionNode(tokenLine, &node);
			break;
		case TOKEN_LINE_TERMINAL:
			createTerminalNode(&node);
			break;
		case TOKEN_LINE_TRUE:
			createTrueNode(tokenLine, &node);
			break;
		case TOKEN_LINE_ROLE:
			node = createRoleNode(tokenLine);
			break;
		default:
			throw Exception("Syntax error in line: " + tokenLine.toString());
	}
	return node;
}

void GDLNode::breakDownTokenLine(const TokenLine &tokenLine, std::vector<TokenLine> &tokenLinesOut) {
	TokenLiner tokenLiner;
	tokenLiner.createLines(tokenLine.getTokens(), tokenLinesOut);
}

GDLNode *GDLNode::createRelationNode(const TokenLine &tokenLine) {
	std::vector<TokenLine> tokenLines;
	
	breakDownTokenLine(tokenLine, tokenLines);
	try {
		std::string name = tokenLines.at(0).getTokens().at(0).getTokenStr();
		std::vector<Token> arguments;
		for (size_t i = 1; i < tokenLines.size(); ++i) {
			if (tokenLines[i].getTokens().at(0).getType() != TOKENIZER_TOKEN_TYPE_TERM) {
				throw Exception("Syntax error: Invalid arguments in relation. In line: " + tokenLine.toString());
			}
			arguments.push_back(tokenLines[i].getTokens().at(0));
		}
		return (new RelationNode(name, arguments));
	} catch (std::out_of_range) {
		throw Exception("Syntax error while creating Relation node. In line: " + tokenLine.toString());
	}
}

GDLNode *GDLNode::createRoleNode(const TokenLine &tokenLine) {
	std::vector<TokenLine> tokenLines;
	
	breakDownTokenLine(tokenLine, tokenLines);
	try {
		int type = tokenLines.at(1).getTokens().at(0).getType();
		if (type != TOKENIZER_TOKEN_TYPE_TERM && type != TOKENIZER_TOKEN_TYPE_VAR) {
			throw Exception("Syntax error: Invalid argument for role. In line: " + tokenLine.toString());
		}
		return (new RoleNode(tokenLines[1].getTokens()[0]));
	} catch (std::out_of_range) {
		throw Exception("Syntax error while creating Role node. In line: " + tokenLine.toString());
	}
}

void GDLNode::createBaseNode(const TokenLine &tokenLine, GDLNode **nodeOut) {
	std::vector<TokenLine> tokenLines;
	PropositionNode *proposition;
	
	breakDownTokenLine(tokenLine, tokenLines);
	try {
		if (tokenLines.at(1).getType() != TOKEN_LINE_RELATION) {
			throw Exception("Syntax error: Base must have proposition as argument. In line: " + tokenLine.toString());
		}
		
		createPropositionNode(tokenLines.at(1), (GDLNode**)&proposition);
		*nodeOut = new BaseNode(proposition);
	} catch (std::out_of_range) {
		throw Exception("Syntax error while creating base node. In line: " + tokenLine.toString());
	}
}

void GDLNode::createIfNode(const TokenLine &tokenLine, GDLNode **nodeOut) {
	std::vector<TokenLine> tokenLines;
	
	breakDownTokenLine(tokenLine, tokenLines);
	try {
		GDLNode *head = createGDLNodes(tokenLines.at(1));
		std::vector<GDLNode*> body;
		for (size_t i = 2; i < tokenLines.size(); ++i) {
			GDLNode *b = createGDLNodes(tokenLines[i]);
			body.push_back(b);
		}
		*nodeOut = new IfNode(head, body);
	} catch (std::out_of_range) {
		throw Exception("Syntax error while creating If node. In line: " + tokenLine.toString());
	}
}

void GDLNode::createLegalNode(const TokenLine &tokenLine, GDLNode **nodeOut) {
	std::vector<TokenLine> tokenLines;
	
	breakDownTokenLine(tokenLine, tokenLines);
	try {
		int type = tokenLines.at(1).getTokens().at(0).getType();
		if (type != TOKENIZER_TOKEN_TYPE_VAR && type != TOKENIZER_TOKEN_TYPE_TERM) {
			throw Exception("Syntax error: Legal should have role as first argument. In line: " + tokenLine.toString());
		}
		if (tokenLines.at(2).getType() != TOKEN_LINE_RELATION) {
			throw Exception("Syntax error: Legal should have action as second argument. In line: " + tokenLine.toString());
		}
		
		Token role = tokenLines[1].getTokens()[0];
		PropositionNode *proposition;
		createPropositionNode(tokenLines[2],(GDLNode**)&proposition);
		*nodeOut = new LegalNode(role, proposition);
	} catch (std::out_of_range) {
		throw Exception("Syntax error while creating Legal node. In line: " + tokenLine.toString());
	}
}

void GDLNode::createTrueNode(const TokenLine &tokenLine,GDLNode **nodeOut) {
	std::vector<TokenLine> tokenLines;
	
	breakDownTokenLine(tokenLine, tokenLines);
	try {
		if (tokenLines.at(1).getType() != TOKEN_LINE_RELATION) {
			throw Exception("Syntax error: True must have proposition as argument. In line: " + tokenLine.toString());
		}
		
		PropositionNode *proposition;
		createPropositionNode(tokenLines.at(1), (GDLNode**)&proposition);
		*nodeOut = new TrueNode(proposition);
	} catch (std::out_of_range) {
		throw Exception("Syntax error while creating True node. In line: " + tokenLine.toString());
	}
}

void GDLNode::createNotNode(const TokenLine &tokenLine, GDLNode **nodeOut) {
	std::vector<TokenLine> tokenLines;
	
	breakDownTokenLine(tokenLine, tokenLines);
	try {
		if (tokenLines.at(1).getType() != TOKEN_LINE_RELATION) {
			throw Exception("Syntax error: Not must have proposition as argument. In line: " + tokenLine.toString());
		}
		
		PropositionNode *proposition;
		createPropositionNode(tokenLines.at(1), (GDLNode**)&proposition);
		*nodeOut = new NotNode(proposition);
	} catch (std::out_of_range) {
		throw Exception("Syntax error while creating Not node In line: " + tokenLine.toString());
	}
}

void GDLNode::createNextNode(const TokenLine &tokenLine, GDLNode **nodeOut) {
	std::vector<TokenLine> tokenLines;
	
	breakDownTokenLine(tokenLine, tokenLines);
	try {
		if (tokenLines.at(1).getType() != TOKEN_LINE_RELATION) {
			throw Exception("Syntax error: Next must have proposition as argument. In line: " + tokenLine.toString());
		}
		
		PropositionNode *proposition;
		createPropositionNode(tokenLines.at(1), (GDLNode**)&proposition);
		*nodeOut = new NextNode(proposition);
	} catch (std::out_of_range) {
		throw Exception("Syntax error while creating Next node. In line: " + tokenLine.toString());
	}
}

void GDLNode::createOrNode(const TokenLine &tokenLine, GDLNode **nodeOut) {
	std::vector<TokenLine> tokenLines;
	
	breakDownTokenLine(tokenLine, tokenLines);
	try {
		std::vector<PropositionNode*> propositions;
		for (size_t i = 1; i < tokenLines.size(); ++i) {
			try {
				if (tokenLines[i].getType() != TOKEN_LINE_RELATION && tokenLines[i].getType() != TOKEN_LINE_DISTINCT) {
					throw Exception("Syntax error: Or must have proposition as arguments. In line: " + tokenLine.toString());
				}
				
				PropositionNode *proposition;
				createPropositionNode(tokenLines[i], (GDLNode**)&proposition);
				propositions.push_back(proposition);
			} catch (Exception &e) {
				for (size_t i = 0; i < propositions.size(); ++i) {
					delete propositions[i];
				}
				throw e;
			}
		}
		*nodeOut = new OrNode(propositions);
	} catch (std::out_of_range) {
		throw Exception("Syntax error while creating Or node. In line: " + tokenLine.toString());
	}
}

void GDLNode::createTerminalNode(GDLNode **nodeOut) {
	*nodeOut = new TerminalNode();
}

void GDLNode::createGoalNode(const TokenLine &tokenLine, GDLNode **nodeOut) {
	std::vector<TokenLine> tokenLines;
	
	breakDownTokenLine(tokenLine, tokenLines);
	try {
		int type = tokenLines.at(1).getTokens().at(0).getType();
		if (type != TOKENIZER_TOKEN_TYPE_TERM && type != TOKENIZER_TOKEN_TYPE_VAR) {
			throw Exception("Syntax error: Goal must have role as first argument. In line: " + tokenLine.toString());
		}
		if (tokenLines.at(2).getTokens().at(0).getType() != TOKENIZER_TOKEN_TYPE_TERM) {
			throw Exception("Syntax error: Goal must have value as second argument. In line: " + tokenLine.toString());
		}
		
		Token role = tokenLines[1].getTokens()[0];
		int value = stoi(tokenLines[2].getTokens()[0].getTokenStr());
		*nodeOut = new GoalNode(role, value);
	} catch (std::out_of_range) {
		throw Exception("Syntax error while creating Goal node. In line: " + tokenLine.toString());
	}
}

void GDLNode::createRuleNode(const TokenLine &tokenLine, GDLNode **nodeOut) {
	
}

void GDLNode::createPropositionNode(const TokenLine &tokenLine, GDLNode **nodeOut) {
	std::vector<TokenLine> tokenLines;
	
	breakDownTokenLine(tokenLine, tokenLines);
	try {
		std::string name;
		std::vector<Token> arguments;
		
		name = tokenLines.at(0).getTokens().at(0).getTokenStr();
		for (size_t i = 1; i < tokenLines.size(); ++i) {
			int type = tokenLines.at(i).getTokens().at(0).getType();
			if (type != TOKENIZER_TOKEN_TYPE_TERM && type != TOKENIZER_TOKEN_TYPE_VAR) {
				throw Exception("Syntax error: Proposition '" + name + "' has incorrect arguments. In line: " + tokenLine.toString());
			}
			arguments.push_back(tokenLines.at(i).getTokens().at(0));
		}
		*nodeOut = new PropositionNode(name, arguments);
	} catch (std::out_of_range) {
		throw Exception("Syntax error while creating Proposition node. In line: " + tokenLine.toString());
	}
}

void GDLNode::createInputNode(const TokenLine &tokenLine, GDLNode **nodeOut) {
	std::vector<TokenLine> tokenLines;
	
	breakDownTokenLine(tokenLine, tokenLines);
	try {
		int type = tokenLines.at(1).getTokens().at(0).getType();
		if (type != TOKENIZER_TOKEN_TYPE_TERM && type != TOKENIZER_TOKEN_TYPE_VAR) {
			throw Exception("Syntax error: Input must have role as first argument. In line: " + tokenLine.toString());
		}
		if (tokenLines.at(2).getType() != TOKEN_LINE_RELATION) {
			throw Exception("Syntax error: Input must have action as second argument. In line: " + tokenLine.toString());
		}
		
		Token role = tokenLines[1].getTokens()[0];
		PropositionNode *proposition;
		createPropositionNode(tokenLines[2], (GDLNode**)&proposition);
		*nodeOut = new InputNode(role, proposition);
	} catch (std::out_of_range) {
		throw Exception("Syntax error while creating Input node. In line: " + tokenLine.toString());
	}
}

void GDLNode::createDistinctNode(const TokenLine &tokenLine, GDLNode **nodeOut) {
	std::vector<TokenLine> tokenLines;
	std::vector<Token> arguments;
	
	breakDownTokenLine(tokenLine, tokenLines);
	for (size_t i = 1; i < tokenLines.size(); ++i) {
		int type = tokenLines[i].getTokens()[0].getType();
		if (type != TOKENIZER_TOKEN_TYPE_TERM && type != TOKENIZER_TOKEN_TYPE_VAR) {
			throw Exception("Syntax error: Invalid arguments in Distinct. In line: " + tokenLine.toString());
		}
		arguments.push_back(tokenLines[i].getTokens()[0]);
	}
	*nodeOut = new DistinctNode(arguments);
}

void GDLNode::createDoesNode(const TokenLine &tokenLine, GDLNode **nodeOut) {
	std::vector<TokenLine> tokenLines;
	
	breakDownTokenLine(tokenLine, tokenLines);
	try {
		int type = tokenLines.at(1).getTokens().at(0).getType();
		if (type != TOKENIZER_TOKEN_TYPE_TERM && type != TOKENIZER_TOKEN_TYPE_VAR) {
			throw Exception("Syntax error: Does must have role as first argument. In line: " + tokenLine.toString());
		}
		if (tokenLines.at(2).getType() != TOKEN_LINE_RELATION) {
			throw Exception("Syntax error: Does must have action as second argument. In line: " + tokenLine.toString());
		}
		
		Token role = tokenLines[1].getTokens()[0];
		PropositionNode *proposition;
		createPropositionNode(tokenLines[2], (GDLNode**)&proposition);
		*nodeOut = new DoesNode(role, proposition);
	} catch (std::out_of_range) {
		throw Exception("Syntax error while creating Does node. In line: " + tokenLine.toString());
	}
}

void GDLNode::createInitNode(const TokenLine &tokenLine, GDLNode **nodeOut) {
	std::vector<TokenLine> tokenLines;
	PropositionNode *proposition;
	
	breakDownTokenLine(tokenLine, tokenLines);
	try {
		if (tokenLines.at(1).getType() != TOKEN_LINE_RELATION) {
			throw Exception("Syntax error: Init must have proposition as argument. In line: " + tokenLine.toString());
		}
		
		createPropositionNode(tokenLines.at(1), (GDLNode**)&proposition);
		*nodeOut = new InitNode(proposition);
	} catch (std::out_of_range) {
		throw Exception("Syntax error while creating init node. In line: " + tokenLine.toString());
	}
}

void GDLNode::addToVarTable(std::string varName, std::string propName, size_t index, VarTable &varTableOut) const {
	VarTable::iterator it = varTableOut.find(varName);
	if (it != varTableOut.end()) {
		it->second.addAddress(VarAddress(propName, index));
	} else {
		Variable variable(varName);
		variable.addAddress(VarAddress(propName, index));
		std::pair<std::string, Variable> entry(varName, variable);
		varTableOut.insert(entry);
	}
}