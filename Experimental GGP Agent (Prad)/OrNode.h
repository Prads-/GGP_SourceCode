#ifndef ORNODE_H
#define ORNODE_H

#include <vector>
#include "GDLNode.h"
#include "PropositionNode.h"

class OrNode : public GDLNode {
private:
	std::vector<PropositionNode*> propositions;
	
public:
	OrNode(const std::vector<PropositionNode*> &propositions);
	~OrNode();
	
	int getInstanceOf() const;
};

#endif