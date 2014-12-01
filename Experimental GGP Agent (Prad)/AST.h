#ifndef AST_H
#define AST_H

#include <vector>
#include "GDLNode.h"
#include "TokenLine.h"

class AST {
public:
	void createAST(const std::vector<TokenLine> &tokenLines, std::vector<GDLNode*> &astOut);
};

#endif