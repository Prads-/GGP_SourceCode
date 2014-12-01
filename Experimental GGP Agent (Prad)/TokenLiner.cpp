#include <stdexcept>
#include "TokenLiner.h"
#include "TokenType.h"
#include "TokenLineType.h"
#include "Exception.h"

void TokenLiner::createLines(const std::vector<Token> &tokens, std::vector<TokenLine> &tokenLinesOut) const {
	for (size_t i = 0; i < tokens.size(); ++i) {
		TokenLine tokenLine;
		
		if (tokens[i].getType() == TOKENIZER_TOKEN_TYPE_OPEN) {
			std::vector<Token> line = getLine(tokens, ++i);
			
			try {
				tokenLine.setType(getTokenLineTypeFromFirstToken(line.at(0)));
			} catch (std::out_of_range) {
				continue;
			}
			
			for (Token &token : line) {
				tokenLine.addToken(token);
			}
		} else {
			tokenLine.setType(getTokenLineTypeFromFirstToken(tokens[i]));
			tokenLine.addToken(tokens[i]);
		}
		tokenLinesOut.push_back(tokenLine);
	}
}

int TokenLiner::getTokenLineTypeFromFirstToken(const Token &token) const {
	switch (token.getType()) {
		case TOKENIZER_TOKEN_TYPE_KEYWORD_BASE:
			return TOKEN_LINE_BASE;
		case TOKENIZER_TOKEN_TYPE_KEYWORD_DISTINCT:
			return TOKEN_LINE_DISTINCT;
		case TOKENIZER_TOKEN_TYPE_KEYWORD_DOES:
			return TOKEN_LINE_DOES;
		case TOKENIZER_TOKEN_TYPE_KEYWORD_GOAL:
			return TOKEN_LINE_GOAL;
		case TOKENIZER_TOKEN_TYPE_KEYWORD_INIT:
			return TOKEN_LINE_INIT;
		case TOKENIZER_TOKEN_TYPE_KEYWORD_INPUT:
			return TOKEN_LINE_INPUT;
		case TOKENIZER_TOKEN_TYPE_KEYWORD_LEGAL:
			return TOKEN_LINE_LEGAL;
		case TOKENIZER_TOKEN_TYPE_KEYWORD_NEXT:
			return TOKEN_LINE_NEXT;
		case TOKENIZER_TOKEN_TYPE_KEYWORD_ROLE:
			return TOKEN_LINE_ROLE;
		case TOKENIZER_TOKEN_TYPE_KEYWORD_TERMINAL:
			return TOKEN_LINE_TERMINAL;
		case TOKENIZER_TOKEN_TYPE_KEYWORD_TRUE:
			return TOKEN_LINE_TRUE;
		case TOKENIZER_TOKEN_TYPE_OPERATOR_IF:
			return TOKEN_LINE_IF;
		case TOKENIZER_TOKEN_TYPE_OPERATOR_NOT:
			return TOKEN_LINE_NOT;
		case TOKENIZER_TOKEN_TYPE_OPERATOR_OR:
			return TOKEN_LINE_OR;
		case TOKENIZER_TOKEN_TYPE_TERM:
			return TOKEN_LINE_RELATION;
		case TOKENIZER_TOKEN_TYPE_VAR:
			return TOKEN_LINE_VAR;
		default:
			throw Exception("Sytax error: Unknown token line type. Cause by token: " + token.getTokenStr());
	}
}

std::vector<Token> TokenLiner::getLine(const std::vector<Token> &tokens, size_t &index) const {
	std::vector<Token> retTokens;
	int scopeCounter = 1;
	
	do {
		if (tokens.at(index).getType() == TOKENIZER_TOKEN_TYPE_OPEN) {
			++scopeCounter;
		} else if (tokens.at(index).getType() == TOKENIZER_TOKEN_TYPE_CLOSE) {
			--scopeCounter;
		}
		retTokens.push_back(tokens.at(index++));
	} while (scopeCounter > 0 && index < tokens.size());
	--index;
	retTokens.pop_back();
	stripParenthesis(retTokens);
	
	return retTokens;
}

void TokenLiner::stripParenthesis(std::vector<Token> &tokens) const {
	while (tokens.at(0).getType() == TOKENIZER_TOKEN_TYPE_OPEN) {
		if (tokens.at(tokens.size() - 1).getType() == TOKENIZER_TOKEN_TYPE_CLOSE) {
			tokens.pop_back();
			tokens.erase(tokens.begin());
		} else {
			throw Exception("Syntax error in line: " + tokensToLine(tokens));
		}
	}
}

std::string TokenLiner::tokensToLine(const std::vector<Token> &tokens) const {
	std::string retStr = "";
	for (const Token &token : tokens) {
		retStr += token.getTokenStr() + " ";
	}
	return retStr;
}