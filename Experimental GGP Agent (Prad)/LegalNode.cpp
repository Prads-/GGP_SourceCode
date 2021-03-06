#include <iostream>
#include "LegalNode.h"
#include "TokenType.h"

LegalNode::LegalNode(const Token &role, PropositionNode *action) {
	this->role = role;
	this->action = action;
}

LegalNode::~LegalNode() {
	delete action;
}

int LegalNode::getInstanceOf() const {
	return INSTANCE_OF_LEGAL_NODE;
}

void LegalNode::print(std::string indent) const {
	std::cout << indent << "Legal Node" << std::endl;
	indent.push_back('\t');
	std::cout << indent << "Role: ";
	role.print();
	action->print(indent);
	indent.pop_back();
}

const Token &LegalNode::getRole() const {
	return role;
}

const PropositionNode *LegalNode::getAction() const {
	return action;
}

void LegalNode::getVarTable(VarTable &varTableOut) const {
	if (role.getType() == TOKENIZER_TOKEN_TYPE_VAR) {
		addToVarTable(role.getTokenStr(), "role", 0, varTableOut);
	}
	action->getVarTable(varTableOut);
}