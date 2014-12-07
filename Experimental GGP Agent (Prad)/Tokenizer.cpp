#include <algorithm>
#include "Tokenizer.h"
#include "Exception.h"
#include "TokenType.h"

int Tokenizer::isKeyword(const std::string &term) const {
	if (term == "distinct") {
		return TOKENIZER_TOKEN_TYPE_KEYWORD_DISTINCT;
	} else if (term == "does") {
		return TOKENIZER_TOKEN_TYPE_KEYWORD_DOES;
	} else if (term == "goal") {
		return TOKENIZER_TOKEN_TYPE_KEYWORD_GOAL;
	} else if (term == "init") {
		return TOKENIZER_TOKEN_TYPE_KEYWORD_INIT;
	} else if (term == "legal") {
		return TOKENIZER_TOKEN_TYPE_KEYWORD_LEGAL;
	} else if (term == "next") {
		return TOKENIZER_TOKEN_TYPE_KEYWORD_NEXT;
	} else if (term == "role") {
		return TOKENIZER_TOKEN_TYPE_KEYWORD_ROLE;
	} else if (term == "terminal") {
		return TOKENIZER_TOKEN_TYPE_KEYWORD_TERMINAL;
	} else if (term == "true") {
		return TOKENIZER_TOKEN_TYPE_KEYWORD_TRUE;
	} else if (term == "base") {
		return TOKENIZER_TOKEN_TYPE_KEYWORD_BASE;
	} else if (term == "input") {
		return TOKENIZER_TOKEN_TYPE_KEYWORD_INPUT;
	}
	return -1;
}
	
int Tokenizer::isOperator(const std::string &term) const {
	if (term == "<=") {
		return TOKENIZER_TOKEN_TYPE_OPERATOR_IF;
	} else if (term == "not") {
		return TOKENIZER_TOKEN_TYPE_OPERATOR_NOT;
	} else if (term == "or")  {
		return TOKENIZER_TOKEN_TYPE_OPERATOR_OR;
	}
	return -1;
}

void Tokenizer::tokenize(std::string path, std::vector<Token> &tokensOut) const {
	std::ifstream file(path);
	
	if (file.is_open()) {
		tokenize(file, tokensOut);
	} else {
		throw Exception("GDL file couldn't be open: " + path);
	}
}

void Tokenizer::tokenize(std::ifstream &file, std::vector<Token> &tokensOut) const {
	std::string line;
	
	while (std::getline(file, line)) {
		tokenize(tokensOut, line);
	}
}

void Tokenizer::tokenize(std::vector<Token> &tokensOut, const std::string &line) const {
	for (size_t i = 0; i < line.size(); ++i) {
		switch (line[i]) {
			case '\t':
			case '\n':
			case '\r':
			case ' ':
				break;
			case ';':
				return;
			case '(':
				tokensOut.push_back(Token("(", TOKENIZER_TOKEN_TYPE_OPEN));
				break;
			case ')':
				tokensOut.push_back(Token(")", TOKENIZER_TOKEN_TYPE_CLOSE));
				break;
			case '?':
			{
				std::string variable = subString(line, ++i);
				toLower(variable);
				tokensOut.push_back(Token(variable, TOKENIZER_TOKEN_TYPE_VAR));
				break;
			}
			default:
			{
				std::string term = subString(line, i);
				toLower(term);
				int tokenType;
				if ((tokenType = isKeyword(term)) != -1 || (tokenType = isOperator(term)) != -1) {
					tokensOut.push_back(Token(term, tokenType));
				} else {
					tokensOut.push_back(Token(term, TOKENIZER_TOKEN_TYPE_TERM));
				}
			}
		}
	}
}

std::string Tokenizer::subString(const std::string &line, size_t &counter) const {
	std::string retStr;
	
	for ( ; counter < line.size(); ++counter) {
		if (line[counter] == ' ' || line[counter] == ')' || line[counter] == '(' ||
				line[counter] == '\t' || line[counter] == '\r' || line[counter] == '\n') {
			--counter;
			break;
		}
		retStr.push_back(line[counter]);
	}
	return retStr;
}

 void Tokenizer::toLower(std::string &word) const {
	for (size_t i = 0; i < word.size(); ++i) {
		if (word[i] >= 65 && word[i] <= 90) {
			word[i] += 32;
		}
	}
}