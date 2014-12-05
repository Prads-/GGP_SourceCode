#ifndef NEXT_NODE_H
#define NEXT_NODE_H

#include "GDLNode.h"
#include "PropositionNode.h"

class NextNode : public GDLNode {
private:
	PropositionNode *proposition;
	
public:
	NextNode(PropositionNode *proposition);
	~NextNode();
	
	int getInstanceOf() const;
	void print(std::string indent) const;
	
	const PropositionNode *getProposition() const;
};

#endif // NEXTNODE_H
