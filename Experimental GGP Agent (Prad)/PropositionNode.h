#ifndef PROPOSITION_NODE_H
#define PROPOSITION_NODE_H

#include <string>
#include <vector>
#include "Token.h"
#include "GDLNode.h"

class PropositionNode : public GDLNode {
private:
	std::string name;
	std::vector<Token> arguments;
	
public:
	PropositionNode(const std::string &name, const std::vector<Token> &arguments);
	
	int getInstanceOf() const;
	void print(std::string indent) const;
	
	std::string getName() const;
	const std::vector<Token> &getArguments() const;
};

#endif
