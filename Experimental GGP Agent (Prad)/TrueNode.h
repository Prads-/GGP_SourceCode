#ifndef TRUENODE_H
#define TRUENODE_H

#include "GDLNode.h"
#include "PropositionNode.h"

class TrueNode : public GDLNode {
private:
	PropositionNode *proposition;
	
public:
	TrueNode(PropositionNode *proposition);
	~TrueNode();
	
	int getInstanceOf() const;
};

#endif // TRUENODE_H
