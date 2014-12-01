#include <iostream>
#include "TerminalNode.h"

int TerminalNode::getInstanceOf() const {
	return INSTANCE_OF_TERMINAL_NODE;
}

void TerminalNode::print(std::string indent) const {
	std::cout << indent << "Terminal Node" << std::endl;
}