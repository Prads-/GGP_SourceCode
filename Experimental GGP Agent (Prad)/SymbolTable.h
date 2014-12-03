#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <unordered_map>
#include <string>
#include <vector>
#include "Symbol.h"
#include "GDLNode.h"
#include "RoleNode.h"
#include "RelationNode.h"
#include "PropositionNode.h"
#include "IfNode.h"

typedef std::unordered_map<std::string, Symbol*> STable;

class SymbolTable {
private:
	STable table;
	std::vector<std::string> roles;
	
	void addRole(const RoleNode *roleNode);
	void addRelation(const RelationNode *relationNode);
	void addProposition(const PropositionNode *propositionNode);
	void checkIfNode(const IfNode *ifNode);
	
public:
	~SymbolTable();

	void addSymbols(const std::vector<GDLNode*> &ast);
	
	static bool argumentExists(const std::vector<std::string> &arguments, const std::string &argument);
};

#endif
