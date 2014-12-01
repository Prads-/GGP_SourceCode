#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <unordered_map>
#include <string>
#include "Symbol.h"

class SymbolTable {
private:
	std::unordered_map<std::string, Symbol> table;
	
};

#endif
