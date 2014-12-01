#ifndef DOES_NODE_H
#define DOES_NODE_H

#include "GDLNode.h"
#include "Token.h"
#include "PropositionNode.h"

class DoesNode : public GDLNode {
private:
	Token role;
	PropositionNode *action;
	
public:
	DoesNode(const Token &role, PropositionNode *action);
	~DoesNode();
	
	int getInstanceOf() const;
	void print(std::string indent) const;
};

#endif
