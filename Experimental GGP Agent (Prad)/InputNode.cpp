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