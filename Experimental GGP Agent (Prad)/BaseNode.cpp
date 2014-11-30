#include "BaseNode.h"

BaseNode::~BaseNode() {
	delete proposition;
}

BaseNode::BaseNode(PropositionNode *proposition) {
	this->proposition = proposition;
}

const PropositionNode *BaseNode::getPropositionNode() const {
	return proposition;
}

int BaseNode::getInstanceOf() const {
	return INSTANCE_OF_BASE_NODE;
}