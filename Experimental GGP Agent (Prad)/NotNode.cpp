#include <iostream>
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

void NotNode::print(std::string indent) const {
	std::cout << indent << "Not Node" << std::endl;
	indent.push_back('\t');
	proposition->print(indent);
	indent.pop_back();
}

const PropositionNode *NotNode::getProposition() const {
	return proposition;
}

void NotNode::getVarTable(VarTable &varTableOut) const {
	proposition->getVarTable(varTableOut);
}