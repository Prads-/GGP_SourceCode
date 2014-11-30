#ifndef GOALNODE_H
#define GOALNODE_H

#include "GDLNode.h"

class GoalNode : public GDLNode {
private:
	Token role;
	int value;
	
public:
	GoalNode(const Token &role, int value);

	int getInstanceOf() const;
};

#endif // GOALNODE_H
