#include <iostream>
#include "InitNode.h"

InitNode::InitNode(PropositionNode *proposition) {
	this->proposition = proposition;
}
	
int InitNode::getInstanceOf() const {
	return INSTANCE_OF_INIT_NODE;
}

void InitNode::print(std::string indent) const {
	std::cout << indent << "Init Node" << std::endl;
	indent.push_back('\t');
	proposition->print(indent);
	indent.pop_back();
}