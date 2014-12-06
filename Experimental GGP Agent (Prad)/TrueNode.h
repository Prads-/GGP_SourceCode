#ifndef TRUE_NODE_H
#define TRUE_NODE_H

#include "GDLNode.h"
#include "PropositionNode.h"

class TrueNode : public GDLNode {
private:
	PropositionNode *proposition;
	
public:
	TrueNode(PropositionNode *proposition);
	~TrueNode();
	
	int getInstanceOf() const;
	void print(std::string indent) const;
	
	const PropositionNode *getProposition() const;
	void getVarTable(VarTable &varTableOut) const;
};

#endif // TRUENODE_H
