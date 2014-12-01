#include <iostream>
#include "IfNode.h"

IfNode::IfNode(GDLNode *head, const std::vector<GDLNode*> body) {
	this->head = head;
	this->body = body;
}

IfNode::~IfNode() {
	delete head;
	for (size_t i = 0; i < body.size(); ++i) {
		delete body[i];
	}
}

int IfNode::getInstanceOf() const {
	return INSTANCE_OF_IF_NODE;
}

void IfNode::print(std::string indent) const {
	std::cout << indent << "If Node" << std::endl;
	indent.push_back('\t');
	std::cout << indent << "Head:" << std::endl; 
	head->print(indent);
	std::cout << indent << "Body:" << std::endl;
	for (GDLNode *node : body) {
		node->print(indent);
	}
	indent.pop_back();
}