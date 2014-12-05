#include <iostream>
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

void TrueNode::print(std::string indent) const {
	std::cout << indent << "True Node" << std::endl;
	indent.push_back('\t');
	proposition->print(indent);
	indent.pop_back();
}

const PropositionNode *TrueNode::getProposition() const {
	return proposition;
}