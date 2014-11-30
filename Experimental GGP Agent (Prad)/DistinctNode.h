#ifndef DISTINCTNODE_H
#define DISTINCTNODE_H

#include <vector>
#include "GDLNode.h"
#include "Token.h"

class DistinctNode : public GDLNode {
private:
	std::vector<Token> arguments;

public:
	DistinctNode(const std::vector<Token> &arguments);
	
	int getInstanceOf() const;
};

#endif