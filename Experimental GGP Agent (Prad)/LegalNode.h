#ifndef LEGAL_NODE_H
#define LEGAL_NODE_H

#include "Token.h"
#include "PropositionNode.h"
#include "GDLNode.h"

class LegalNode : public GDLNode {
private:
	Token role;
	PropositionNode *action;
	
public:
	LegalNode(const Token &role, PropositionNode *action);
	~LegalNode();
	
	int getInstanceOf() const;
	void print(std::string indent) const;
	
	const Token &getRole() const;
	const PropositionNode *getAction() const;
	void getVarTable(VarTable &varTableOut) const;
};

#endif