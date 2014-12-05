#include <iostream>
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

void BaseNode::print(std::string indent) const {
	std::cout << indent << "Base Node" << std::endl;
	indent.push_back('\t');
	proposition->print(indent);
	indent.pop_back();
}

const PropositionNode *BaseNode::getProposition() const {
	return proposition;
}