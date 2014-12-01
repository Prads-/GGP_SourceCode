#include <iostream>
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

void NextNode::print(std::string indent) const {
	std::cout << indent << "Next Node" << std::endl;
	indent.push_back('\t');
	proposition->print(indent);
	indent.pop_back();
}