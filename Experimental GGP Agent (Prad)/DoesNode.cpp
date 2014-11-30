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