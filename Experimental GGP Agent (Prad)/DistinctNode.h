#ifndef DISTINCT_NODE_H
#define DISTINCT_NODE_H

#include <vector>
#include "GDLNode.h"
#include "Token.h"

class DistinctNode : public GDLNode {
private:
	std::vector<Token> arguments;

public:
	DistinctNode(const std::vector<Token> &arguments);
	
	int getInstanceOf() const;
	void print(std::string indent) const;
};

#endif