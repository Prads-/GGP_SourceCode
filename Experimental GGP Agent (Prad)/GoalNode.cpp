#include <iostream>
#include "GoalNode.h"

GoalNode::GoalNode(const Token &role, int value) {
	this->role = role;
	this->value = value;
}

int GoalNode::getInstanceOf() const {
	return INSTANCE_OF_GOAL_NODE;
}

void GoalNode::print(std::string indent) const {
	std::cout << indent << "Goal Node" << std::endl;
	indent.push_back('\t');
	std::cout << indent << "Role: ";
	role.print();
	std::cout << indent << "Value: " << value << std::endl;
	indent.pop_back();
}