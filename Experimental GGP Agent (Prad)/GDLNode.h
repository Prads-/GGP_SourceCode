#ifndef GDL_NODE_H
#define GDL_NODE_H

#include <vector>
#include <string>
#include "TokenLine.h"
#include "VarTable.h"

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
#define INSTANCE_OF_RELATION_NODE			15
#define INSTANCE_OF_ROLE_NODE				16

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
	static void createPropositionNode(const TokenLine &tokenLine, GDLNode **nodeOut);
	static void createInputNode(const TokenLine &tokenLine, GDLNode **nodeOut);
	static void createDistinctNode(const TokenLine &tokenLine, GDLNode **nodeOut);
	static void createDoesNode(const TokenLine &tokenLine, GDLNode **nodeOut);
	static void createInitNode(const TokenLine &tokenLine, GDLNode **nodeOut);
	
	static void breakDownTokenLine(const TokenLine &tokenLine, std::vector<TokenLine> &tokenLinesOut);
	
protected:
	void addToVarTable(std::string varName, std::string propName, size_t index, VarTable &varTableOut) const;
	
public:
	virtual ~GDLNode() { }
	virtual int getInstanceOf() const = 0;
	virtual void print(std::string indent) const = 0;
	virtual void getVarTable(VarTable &varTableOut) const = 0;
	
	static GDLNode *createGDLNodes(const TokenLine &tokenLine);
	static GDLNode *createRelationNode(const TokenLine &tokenLine);
	static GDLNode *createRoleNode(const TokenLine &tokenLine);
};

#endif