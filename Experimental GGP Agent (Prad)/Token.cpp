#include <iostream>
#include "Token.h"
#include "TokenType.h"

Token::Token(std::string tokenStr, int type) : tokenStr(tokenStr), type(type) {
	
}
	
std::string Token::getTokenStr() const {
	return tokenStr;
}

int Token::getType() const {
	return type;
}

std::string Token::getTypeString() const {
	switch (type) {
		case TOKENIZER_TOKEN_TYPE_CLOSE:
			return "Close";
		case TOKENIZER_TOKEN_TYPE_KEYWORD_BASE:
			return "Keyword Base";
		case TOKENIZER_TOKEN_TYPE_KEYWORD_DISTINCT:
			return "Keyword Distinct";
		case TOKENIZER_TOKEN_TYPE_KEYWORD_DOES:
			return "Keyword Does";
		case TOKENIZER_TOKEN_TYPE_KEYWORD_GOAL:
			return "Keyword Goal";
		case TOKENIZER_TOKEN_TYPE_KEYWORD_INIT:
			return "Keyword Init";
		case TOKENIZER_TOKEN_TYPE_KEYWORD_INPUT:
			return "Keyword Input";
		case TOKENIZER_TOKEN_TYPE_KEYWORD_LEGAL:
			return "Keyword Legal";
		case TOKENIZER_TOKEN_TYPE_KEYWORD_NEXT:
			return "Keyword Next";
		case TOKENIZER_TOKEN_TYPE_KEYWORD_ROLE:
			return "Keyword Role";
		case TOKENIZER_TOKEN_TYPE_KEYWORD_TERMINAL:
			return "Keyword Terminal";
		case TOKENIZER_TOKEN_TYPE_KEYWORD_TRUE:
			return "Keyword True";
		case TOKENIZER_TOKEN_TYPE_OPEN:
			return "Open";
		case TOKENIZER_TOKEN_TYPE_OPERATOR_IF:
			return "Operator If";
		case TOKENIZER_TOKEN_TYPE_OPERATOR_NOT:
			return "Operator Not";
		case TOKENIZER_TOKEN_TYPE_OPERATOR_OR:
			return "Operator Or";
		case TOKENIZER_TOKEN_TYPE_TERM:
			return "Term";
		case TOKENIZER_TOKEN_TYPE_VAR:
			return "Variable";
		default:
			return "Unknown";
	}
}

void Token::print(bool typeString, bool newline) const {
	std::cout << tokenStr;
	
	if (typeString) {
		std::cout << ": " << getTypeString();
	}
	
	if (newline) {
		std::cout << std::endl;
	}
}