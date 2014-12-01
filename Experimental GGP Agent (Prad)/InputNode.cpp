#include <iostream>
#include "InputNode.h"

InputNode::InputNode(const Token &role, PropositionNode *action) {
	this->role = role;
	this->action = action;
}

InputNode::~InputNode() {
	delete action;
}
	
int InputNode::getInstanceOf() const {
	return INSTANCE_OF_INPUT_NODE;
}

void InputNode::print(std::string indent) const {
	std::cout << indent << "Input Node" << std::endl;
	indent.push_back('\t');
	std::cout << indent << "Role: ";
	role.print();
	action->print(indent);
	indent.pop_back();
}