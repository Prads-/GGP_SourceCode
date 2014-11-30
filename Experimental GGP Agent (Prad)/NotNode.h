#ifndef NOTNODE_H
#define NOTNODE_H

#include "GDLNode.h"
#include "PropositionNode.h"

class NotNode : public GDLNode {
private:
	PropositionNode *proposition;

public:
	NotNode(PropositionNode *proposition);
	~NotNode();
	
	int getInstanceOf() const;
};

#endif // NOTNODE_H
