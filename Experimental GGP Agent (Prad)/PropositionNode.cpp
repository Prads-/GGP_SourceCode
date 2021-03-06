#include <iostream>
#include "PropositionNode.h"
#include "TokenType.h"

PropositionNode::PropositionNode(const std::string &name, const std::vector<Token> &arguments) {
	this->name = name;
	this->arguments = arguments;
}
	
int PropositionNode::getInstanceOf() const {
	return INSTANCE_OF_PROPOSITION_NODE;
}

void PropositionNode::print(std::string indent) const {
	std::cout << indent << "Proposition Node" << std::endl;
	indent.push_back('\t');
	std::cout << indent << "Name: " << name << std::endl;
	for (const Token &argument : arguments) {
		std::cout << indent;
		argument.print();
	}
	indent.pop_back();
}

std::string PropositionNode::getName() const {
	return name;
}

const std::vector<Token> &PropositionNode::getArguments() const {
	return arguments;
}

void PropositionNode::getVarTable(VarTable &varTableOut) const {
	for (size_t i = 0; i < arguments.size(); ++i) {
		if (arguments[i].getType() == TOKENIZER_TOKEN_TYPE_VAR) {
			addToVarTable(arguments[i].getTokenStr(), name, i, varTableOut);
		}
	}
}