#include <iostream>
#include "TokenLine.h"
#include "TokenLineType.h"

int TokenLine::getType() const {
	return type;
}

const std::vector<Token> &TokenLine::getTokens() const {
	return tokens;
}

std::string TokenLine::getTypeString() const {
	switch (type) {
		case TOKEN_LINE_BASE:
			return "Base";
		case TOKEN_LINE_DISTINCT:
			return "Distinct";
		case TOKEN_LINE_DOES:
			return "Does";
		case TOKEN_LINE_RELATION:
			return "Relation";
		case TOKEN_LINE_GOAL:
			return "Goal";
		case TOKEN_LINE_IF:
			return "If";
		case TOKEN_LINE_INIT:
			return "Init";
		case TOKEN_LINE_INPUT:
			return "Input";
		case TOKEN_LINE_LEGAL:
			return "Legal";
		case TOKEN_LINE_NEXT:
			return "Next";
		case TOKEN_LINE_ROLE:
			return "Role";
		case TOKEN_LINE_TERMINAL:
			return "Terminal";
		case TOKEN_LINE_TRUE:
			return "True";
		case TOKEN_LINE_NOT:
			return "Not";
		case TOKEN_LINE_OR:
			return "Or";
		default:
			return "Unknown type";
	}
}

void TokenLine::print(bool newline) const {
	for (const Token &token : tokens) {
		token.print(false, false);
		std::cout <<  " ";
	}
	std::cout << " : " << getTypeString();
	if (newline) {
		std::cout << std::endl;
	}
}

void TokenLine::setType(int type) {
	this->type = type;
}
	
void TokenLine::addToken(Token token) {
	tokens.push_back(token);
}
	
void TokenLine::clearTokens() {
	tokens.clear();
} 

std::string TokenLine::toString() const {
	std::string retStr = "";
	
	for (const Token &token : tokens) {
		retStr += token.getTokenStr() + " ";
	}
	
	return retStr;
}