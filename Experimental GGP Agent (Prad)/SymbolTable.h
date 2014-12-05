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
#include "LegalNode.h"
#include "TrueNode.h"
#include "NotNode.h"
#include "NextNode.h"
#include "OrNode.h"
#include "BaseNode.h"
#include "InputNode.h"
#include "DoesNode.h"
#include "InitNode.h"

typedef std::unordered_map<std::string, Symbol*> STable;

class SymbolTable {
private:
	STable table;
	std::vector<std::string> roles;
	
	void addRole(const RoleNode *roleNode);
	void addRelation(const RelationNode *relationNode);
	void addProposition(const PropositionNode *propositionNode, bool isRule = false);
	void addAction(const PropositionNode *action);
	
	void processIfNode(const IfNode *ifNode);
	void processLegalNode(const LegalNode *legalNode);
	void processTrueNode(const TrueNode *trueNode);
	void processNotNode(const NotNode *notNode);
	void processNextNode(const NextNode *nextNode);
	void processOrNode(const OrNode *orNode);
	void processBaseNode(const BaseNode *baseNode);
	void processInputNode(const InputNode *inputNode);
	void processDoesNode(const DoesNode *doesNode);
	void processInitNode(const InitNode *initNode);
	void processGDLNode(const GDLNode *gdlNode, bool isIfHead);
	
public:
	~SymbolTable();

	void addSymbols(const std::vector<GDLNode*> &ast);
	
	void print() const;
	
	static bool argumentExists(const std::vector<std::string> &arguments, const std::string &argument);
};

#endif
