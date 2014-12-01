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
	int numOfArgument;
	std::vector<std::string> *argumentDomains;
	
public:
	Symbol(std::string name, int numOfArgument);
	~Symbol();
};

#endif
