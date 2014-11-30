#include "TrueNode.h"

TrueNode::TrueNode(PropositionNode *proposition) {
	this->proposition = proposition;
}

TrueNode::~TrueNode() {
	delete proposition;
}

int TrueNode::getInstanceOf() const {
	return INSTANCE_OF_TRUE_NODE;
}