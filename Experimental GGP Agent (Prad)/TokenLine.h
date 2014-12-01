#ifndef TOKENLINE_H
#define TOKENLINE_H

#include <vector>
#include <string>
#include "Token.h"

class TokenLine {
private:
	int type;
	std::vector<Token> tokens;
	
public:
	int getType() const;
	const std::vector<Token> &getTokens() const;
	
	void setType(int type);
	void addToken(Token token);
	
	void clearTokens();
	
	std::string getTypeString() const;
	void print(bool newline = true) const;
	std::string toString() const;
};

#endif
