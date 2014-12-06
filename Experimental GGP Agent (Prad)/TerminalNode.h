#ifndef TERMINAL_NODE_H
#define TERMINAL_NODE_H

#include "GDLNode.h"

class TerminalNode : public GDLNode {
public:
	int getInstanceOf() const;
	void print(std::string indent) const;
	
	void getVarTable(VarTable &varTableOut) const { }
};

#endif
