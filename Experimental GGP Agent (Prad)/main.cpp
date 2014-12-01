#include <iostream>
#include <vector>
#include "Tokenizer.h"
#include "TokenLiner.h"
#include "Exception.h"
#include "AST.h"
using namespace std;

int main() {
	try {
		Tokenizer tokenizer;
		vector<Token> tokens;
		tokenizer.tokenize("test.kif", tokens);
	
		TokenLiner tokenLiner;
		vector<TokenLine> tokenLines;
		tokenLiner.createLines(tokens, tokenLines);
		
		vector<GDLNode*> ast;
		AST astCreator;
		
		astCreator.createAST(tokenLines, ast);
		for (GDLNode *node : ast) {
			node->print("");
		}
		
		for (size_t i = 0; i < ast.size(); ++i) {
			delete ast[i];
		}
	} catch (Exception &e) {
		cout << e.getMessage() << endl;
	}
	
	cout << "Done!!!";
	cin.get();
	return 0;
}
