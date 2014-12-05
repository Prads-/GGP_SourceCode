#ifndef BASE_NODE_H
#define BASE_NODE_H

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
	
	void print(std::string indent) const;
	
	const PropositionNode *getProposition() const;
};

#endif
