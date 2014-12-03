#include <iostream>
#include "RoleNode.h"

RoleNode::RoleNode(const Token &role) {
	this->role = role;
}

int RoleNode::getInstanceOf() const {
	return INSTANCE_OF_ROLE_NODE;
}

void RoleNode::print(std::string indent) const {
	std::cout << indent << "Role Node" << std::endl;
	std::cout << indent << '\t' << "Role: ";
	role.print();
}

const Token &RoleNode::getRole() const {
	return role;
}