#ifndef GDLNODE_H
#define GDLNODE_H

#include <vector>
#include "TokenLine.h"

#define INSTANCE_OF_IF_NODE					0
#define INSTANCE_OF_LEGAL_NODE				1
#define INSTANCE_OF_TRUE_NODE				2
#define INSTANCE_OF_NOT_NODE				3
#define INSTANCE_OF_NEXT_NODE				4
#define INSTANCE_OF_OR_NODE					5
#define INSTANCE_OF_TERMINAL_NODE			6
#define INSTANCE_OF_GOAL_NODE				7
#define INSTANCE_OF_RULE_NODE				8
#define INSTANCE_OF_PROPOSITION_NODE		9
#define INSTANCE_OF_BASE_NODE				10
#define INSTANCE_OF_INPUT_NODE				11
#define INSTANCE_OF_DOES_NODE				12
#define INSTANCE_OF_DISTINCT_NODE			13
#define INSTANCE_OF_INIT_NODE				14

class GDLNode {
private:
	static void createBaseNode(const TokenLine &tokenLine, GDLNode **nodeOut);
	static void createIfNode(const TokenLine &tokenLine, GDLNode **nodeOut);
	static void createLegalNode(const TokenLine &tokenLine, GDLNode **nodeOut);
	static void createTrueNode(const TokenLine &tokenLine, GDLNode **nodeOut);
	static void createNotNode(const TokenLine &tokenLine, GDLNode **nodeOut);
	static void createNextNode(const TokenLine &tokenLine, GDLNode **nodeOut);
	static void createOrNode(const TokenLine &tokenLine, GDLNode **nodeOut);
	static void createTerminalNode(GDLNode **nodeOut);
	static void createGoalNode(const TokenLine &tokenLine, GDLNode **nodeOut);
	static void createRuleNode(const TokenLine &tokenLine, GDLNode **nodeOut);
	static void createRelationNode(const TokenLine &tokenLine, GDLNode **nodeOut);
	static void createInputNode(const TokenLine &tokenLine, GDLNode **nodeOut);
	static void createDistinctNode(const TokenLine &tokenLine, GDLNode **nodeOut);
	static void createDoesNode(const TokenLine &tokenLine, GDLNode **nodeOut);
	static void createInitNode(const TokenLine &tokenLine, GDLNode **nodeOut);
	
	static void breakDownTokenLine(const TokenLine &tokenLine, std::vector<TokenLine> &tokenLinesOut);
	
public:
	virtual ~GDLNode() { }
	virtual int getInstanceOf() const = 0;
	
	static GDLNode *createGDLNode(const TokenLine &tokenLine);
};

#endif