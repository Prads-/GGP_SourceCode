#ifndef IF_NODE_H
#define IF_NODE_H

#include <vector>
#include "GDLNode.h"
#include "TokenLine.h"

class IfNode : public GDLNode {
private:
	GDLNode *head;
	std::vector<GDLNode*> body;

public:
	IfNode(GDLNode *head, const std::vector<GDLNode*> body);
	~IfNode();
	
	int getInstanceOf() const;
	void print(std::string indent) const;
	
	const GDLNode *getHead() const;
	const std::vector<GDLNode*> &getBody() const;
	
	void getVarTable(VarTable &varTableOut) const;
};

#endif
