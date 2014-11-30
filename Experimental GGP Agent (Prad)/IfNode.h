#ifndef IFNODE_H
#define IFNODE_H

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
};

#endif
