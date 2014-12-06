#ifndef NOT_NODE_H
#define NOT_NODE_H

#include "GDLNode.h"
#include "PropositionNode.h"

class NotNode : public GDLNode {
private:
	PropositionNode *proposition;

public:
	NotNode(PropositionNode *proposition);
	~NotNode();
	
	int getInstanceOf() const;
	void print(std::string indent) const;
	
	const PropositionNode *getProposition() const;
	void getVarTable(VarTable &varTableOut) const;
};

#endif // NOTNODE_H
