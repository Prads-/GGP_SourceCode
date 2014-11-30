#include "GoalNode.h"

GoalNode::GoalNode(const Token &role, int value) {
	this->role = role;
	this->value = value;
}

int GoalNode::getInstanceOf() const {
	return INSTANCE_OF_GOAL_NODE;
}