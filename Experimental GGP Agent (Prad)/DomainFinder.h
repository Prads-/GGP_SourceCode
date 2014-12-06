#ifndef DOMAIN_FINDER_H
#define DOMAIN_FINDER_H

#include <vector>
#include "SymbolTable.h"
#include "GDLNode.h"
#include "VarTable.h"

class DomainFinder {
private:
	static bool processVarTable(const VarTable *varTable, SymbolTable &symbolTable);
	static bool addArguments(const std::vector<std::string> &source, std::vector<std::string> &dest);
	
public:
	static void findDomain(const std::vector<GDLNode*> &ast, SymbolTable &symbolTable);
};

#endif
