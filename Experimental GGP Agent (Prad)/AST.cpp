#include "AST.h"
#include "TokenLineType.h"
#include "Exception.h"

void AST::createAST(const std::vector<TokenLine> &tokenLines, std::vector<GDLNode*> &astOut) {
	for (const TokenLine &tokenLine : tokenLines) {
		switch (tokenLine.getType()) {
			case TOKEN_LINE_ROLE:
				astOut.push_back(GDLNode::createRoleNode(tokenLine));
				break;
			case TOKEN_LINE_RELATION:
				astOut.push_back(GDLNode::createRelationNode(tokenLine));
				break;
			case TOKEN_LINE_VAR:
				throw Exception("Unexpected symbol: " + tokenLine.toString());
			default:
				astOut.push_back(GDLNode::createGDLNodes(tokenLine));
		}
	}
}