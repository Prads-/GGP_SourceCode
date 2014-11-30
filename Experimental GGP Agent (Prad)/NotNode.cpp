#include "NotNode.h"

NotNode::NotNode(PropositionNode *proposition) {
	this->proposition = proposition;
}

NotNode::~NotNode() {
	delete proposition;
}
	
int NotNode::getInstanceOf() const {
	return INSTANCE_OF_NOT_NODE;
}