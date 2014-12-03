#include <iostream>
#include "RelationNode.h"

RelationNode::RelationNode(const std::string &name, const std::vector<Token> &arguments) {
	this->name = name;
	this->arguments = arguments;
}
	
int RelationNode::getInstanceOf() const {
	return INSTANCE_OF_RELATION_NODE;
}

void RelationNode::print(std::string indent) const {
	std::cout << indent << "Relation Node" << std::endl;
	indent.push_back('\t');
	std::cout << indent << "Name: " << name << std::endl;
	for (const Token &argument : arguments) {
		std::cout << indent;
		argument.print();
	}
	indent.pop_back();
}

std::string RelationNode::getName() const {
	return name;
}

const std::vector<Token> &RelationNode::getArguments() const {
	return arguments;
}