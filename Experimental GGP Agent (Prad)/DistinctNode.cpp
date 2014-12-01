#include <iostream>
#include "DistinctNode.h"

DistinctNode::DistinctNode(const std::vector<Token> &arguments) {
	this->arguments = arguments;
}
	
int DistinctNode::getInstanceOf() const {
	return INSTANCE_OF_DISTINCT_NODE;
}

void DistinctNode::print(std::string indent) const {
	std::cout << indent << "Distinct Node" << std::endl;
	
	indent.push_back('\t');
	for (const Token &token : arguments) {
		std::cout << indent;
		token.print();
	}
	indent.pop_back();
}