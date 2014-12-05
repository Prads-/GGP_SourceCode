#include <iostream>
#include "DoesNode.h"

DoesNode::DoesNode(const Token &role, PropositionNode *action) {
	this->role = role;
	this->action = action;
}

DoesNode::~DoesNode() {
	delete action;
}
	
int DoesNode::getInstanceOf() const {
	return INSTANCE_OF_DOES_NODE;
}

void DoesNode::print(std::string indent) const {
	std::cout << indent << "Does Node" << std::endl;
	indent.push_back('\t');
	std::cout << indent << "Role: ";
	role.print();
	action->print(indent);
	indent.pop_back();
}

const Token &DoesNode::getRole() const {
	return role;
}

const PropositionNode *DoesNode::getAction() const {
	return action;
}