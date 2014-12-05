#ifndef OR_NODE_H
#define OR_NODE_H

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
	void print(std::string indent) const;
	
	const std::vector<PropositionNode*> &getPropositions() const;
};

#endif