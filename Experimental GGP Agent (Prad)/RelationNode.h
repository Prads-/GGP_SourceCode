#ifndef RELATION_NODE_H
#define RELATION_NODE_H

#include <string>
#include <vector>
#include "Token.h"
#include "GDLNode.h"

class RelationNode : public GDLNode {
private:
	std::string name;
	std::vector<Token> arguments;
	
public:
	RelationNode(const std::string &name, const std::vector<Token> &arguments);
	
	int getInstanceOf() const;
	void print(std::string indent) const;
};

#endif
