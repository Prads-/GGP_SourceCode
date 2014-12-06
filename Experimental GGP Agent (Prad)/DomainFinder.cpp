#include <unordered_map>
#include <string>
#include "DomainFinder.h"
#include "Exception.h"

void DomainFinder::findDomain(const std::vector<GDLNode*> &ast, SymbolTable &symbolTable) {
	std::vector<VarTable*> varTables;
	
	for (const GDLNode *gdlNode : ast) {
		if (gdlNode->getInstanceOf() == INSTANCE_OF_IF_NODE) {
			VarTable *varTable = new VarTable;
			gdlNode->getVarTable(*varTable);
			varTables.push_back(varTable);
		}
	}
	
	bool newVarAdded;
	do {
		newVarAdded = false;
		for (const VarTable *varTable : varTables) {
			if (processVarTable(varTable, symbolTable)) {
				newVarAdded = true;
			}
		}
	} while(newVarAdded);
	
	for (size_t i = 0; i < varTables.size(); ++i) {
		delete varTables[i];
	}
}

bool DomainFinder::processVarTable(const VarTable *varTable, SymbolTable &symbolTable) {
	bool retVal = false;
	
	for (VarTable::const_iterator it = varTable->begin(); it != varTable->end(); ++it) {
		const std::vector<VarAddress> &varAddresses = it->second.getAddresses();
		for (size_t i = 0; i < varAddresses.size(); ++i) {
			const std::vector<std::string> *sArgumentList;
			if (varAddresses[i].getPropName() == "role") {
				sArgumentList = &symbolTable.getRoles();
			} else {
				Symbol *symbol = symbolTable.getSymbol(varAddresses[i].getPropName());
				if (symbol == 0) {
					throw Exception("Unknown symbol: " + varAddresses[i].getPropName());
				}
				sArgumentList = &symbol->getArgumentDomain(varAddresses[i].getIndex());
			}
			
			for (size_t j = 0; j < varAddresses.size(); ++j) {
				if (j == i || varAddresses[j].getPropName() == "role") {
					continue;
				}
				
				Symbol *symbol = symbolTable.getSymbol(varAddresses[j].getPropName());
				if (symbol == 0) {
					throw Exception("Unknown symbol: " + varAddresses[j].getPropName());
				}
				if (symbol->getType() == SYMBOL_TYPE_RELATION) {
					continue;
				}
				
				std::vector<std::string> &dArgumentList = symbol->getArgumentDomainModifiable(varAddresses[j].getIndex());
				if (addArguments(*sArgumentList, dArgumentList)) {
					retVal = true;
				}
			}
		}
	}
	
	return retVal;
}

bool DomainFinder::addArguments(const std::vector<std::string> &source, std::vector<std::string> &dest) {
	bool retVal = false;
	
	for (const std::string &sStr : source) {
		if (!SymbolTable::argumentExists(dest, sStr)) {
			retVal = true;
			dest.push_back(sStr);
		}
	}
	
	return retVal;
}