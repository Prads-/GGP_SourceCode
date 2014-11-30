#include "LegalNode.h"

LegalNode::LegalNode(const Token &role, PropositionNode *action) {
	this->role = role;
	this->action = action;
}

LegalNode::~LegalNode() {
	delete action;
}

int LegalNode::getInstanceOf() const {
	return INSTANCE_OF_LEGAL_NODE;
}