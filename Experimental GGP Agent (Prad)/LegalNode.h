#ifndef LEGALNODE_H
#define LEGALNODE_H

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
};

#endif