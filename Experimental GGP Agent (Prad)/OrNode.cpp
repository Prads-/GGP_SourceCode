#include "OrNode.h"

OrNode::OrNode(const std::vector<PropositionNode*> &propositions) {
	this->propositions = propositions;
}

OrNode::~OrNode() {
	for (size_t i = 0; i < propositions.size(); ++i) {
		delete propositions[i];
	}
}
	
int OrNode::getInstanceOf() const {
	return INSTANCE_OF_OR_NODE;
}