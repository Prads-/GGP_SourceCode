#include "PropositionNode.h"

PropositionNode::PropositionNode(const std::string &name, const std::vector<Token> &arguments) {
	this->name = name;
	this->arguments = arguments;
}
	
int PropositionNode::getInstanceOf() const {
	return INSTANCE_OF_PROPOSITION_NODE;
}