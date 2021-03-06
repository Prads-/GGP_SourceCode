#include <iostream>
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

void OrNode::print(std::string indent) const {
	std::cout << indent << "Or Node" << std::endl;
	indent.push_back('\t');
	for (PropositionNode *proposition : propositions) {
		proposition->print(indent);
	}
	indent.pop_back();
}

const std::vector<PropositionNode*> &OrNode::getPropositions() const {
	return propositions;
}

void OrNode::getVarTable(VarTable &varTableOut) const {
	for (const PropositionNode *proposition : propositions) {
		proposition->getVarTable(varTableOut);
	}
}