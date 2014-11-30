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