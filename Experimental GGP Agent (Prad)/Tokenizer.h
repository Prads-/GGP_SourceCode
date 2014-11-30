#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>
#include <fstream>
#include "Token.h"

class Tokenizer {
private:
	int isKeyword(const std::string &term) const;
	int isOperator(const std::string &term) const;
	void tokenize(std::ifstream &file, std::vector<Token> &tokensOut) const;
	void tokenize(std::vector<Token> &tokensOut, const std::string &line) const;
	std::string subString(const std::string &line, size_t &counter) const;
	void toLower(std::string &word) const;

public:
	void tokenize(std::string path, std::vector<Token> &tokensOut) const;
};

#endif