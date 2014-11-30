#ifndef DOESNODE_H
#define DOESNODE_H

#include "GDLNode.h"
#include "Token.h"
#include "PropositionNode.h"

class DoesNode : public GDLNode {
private:
	Token role;
	PropositionNode *action;
	
public:
	DoesNode(const Token &role, PropositionNode *action);
	~DoesNode();
	
	int getInstanceOf() const;
};

#endif
