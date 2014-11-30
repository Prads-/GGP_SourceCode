#ifndef TOKENLINER_H
#define TOKENLINER_H

#include <vector>
#include <string>
#include "Token.h"
#include "TokenLine.h"

class TokenLiner {
private:
	int getTokenLineTypeFromFirstToken(const Token &token) const;
	std::vector<Token> getLine(const std::vector<Token> &tokens, size_t &index) const;
	void stripParenthesis(std::vector<Token> &tokens) const;
	
public:
	void createLines(const std::vector<Token> &tokens, std::vector<TokenLine> &tokenLinesOut) const;
	std::string tokensToLine(const std::vector<Token> &tokens) const;
};

#endif