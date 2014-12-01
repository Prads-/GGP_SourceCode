#ifndef GOAL_NODE_H
#define GOAL_NODE_H

#include "GDLNode.h"

class GoalNode : public GDLNode {
private:
	Token role;
	int value;
	
public:
	GoalNode(const Token &role, int value);

	int getInstanceOf() const;
	void print(std::string indent) const;
};

#endif // GOALNODE_H
