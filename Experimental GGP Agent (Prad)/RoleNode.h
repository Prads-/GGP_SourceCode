#ifndef ROLE_NODE_H
#define ROLE_NODE_H

#include "Token.h"
#include "GDLNode.h"

class RoleNode : public GDLNode {
private:
	Token role;
	
public:
	RoleNode(const Token &role);
	
	int getInstanceOf() const;
	void print(std::string indent) const;
};

#endif