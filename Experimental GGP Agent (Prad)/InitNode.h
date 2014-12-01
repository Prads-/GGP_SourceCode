#ifndef INIT_NODE_H
#define INIT_NODE_H

#include "GDLNode.h"
#include "PropositionNode.h"

class InitNode : public GDLNode {
private:
	PropositionNode *proposition;

public:
	InitNode(PropositionNode *proposition);
	
	int getInstanceOf() const;
	void print(std::string indent) const;
};

#endif