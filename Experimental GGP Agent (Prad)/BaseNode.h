#ifndef BASENODE_H
#define BASENODE_H

#include "GDLNode.h"
#include "PropositionNode.h"

class BaseNode : public GDLNode {
private:
	PropositionNode *proposition;
	
public:
	~BaseNode();
	
	int getInstanceOf() const;
	BaseNode(PropositionNode *proposition);
	const PropositionNode *getPropositionNode() const;
};

#endif
