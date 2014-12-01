#ifndef INPUT_NODE_H
#define INPUT_NODE_H

#include "GDLNode.h"
#include "Token.h"
#include "PropositionNode.h"

class InputNode : public GDLNode {
private:
	Token role;
	PropositionNode *action;
	
public:
	InputNode(const Token &role, PropositionNode *action);
	~InputNode();
	
	int getInstanceOf() const;
	void print(std::string indent) const;
};

#endif
