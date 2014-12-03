#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
#include <vector>

enum SymbolType {
	SYMBOL_TYPE_RELATION,
	SYMBOL_TYPE_PROPOSITION,
	SYMBOL_TYPE_RULE
};

class Symbol {
private:
	SymbolType type;
	std::string name;
	size_t numOfArgument;
	std::vector<std::string> *argumentDomains;
	
public:
	Symbol(std::string name, SymbolType type, int numOfArgument);
	~Symbol();
	
	void addArgument(size_t index, const std::string &argument);
	
	size_t getNumOfArgument() const;
	SymbolType getType() const;
	const std::vector<std::string> &getArgumentDomain(size_t index) const;
};

#endif