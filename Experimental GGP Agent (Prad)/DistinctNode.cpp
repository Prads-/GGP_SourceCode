#include "DistinctNode.h"

DistinctNode::DistinctNode(const std::vector<Token> &arguments) {
	this->arguments = arguments;
}
	
int DistinctNode::getInstanceOf() const {
	return INSTANCE_OF_DISTINCT_NODE;
}