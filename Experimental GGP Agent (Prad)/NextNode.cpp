#include "NextNode.h"

NextNode::NextNode(PropositionNode *proposition) {
	this->proposition = proposition;
}

NextNode::~NextNode() {
	delete proposition;
}
	
int NextNode::getInstanceOf() const {
	return INSTANCE_OF_NEXT_NODE;
}