#ifndef NEXTNODE_H
#define NEXTNODE_H

#include "GDLNode.h"
#include "PropositionNode.h"

class NextNode : public GDLNode {
private:
	PropositionNode *proposition;
	
public:
	NextNode(PropositionNode *proposition);
	~NextNode();
	
	int getInstanceOf() const;
};

#endif // NEXTNODE_H
