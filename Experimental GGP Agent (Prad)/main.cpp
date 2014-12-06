#include <iostream>
#include <vector>
#include "Tokenizer.h"
#include "TokenLiner.h"
#include "Exception.h"
#include "AST.h"
#include "SymbolTable.h"
#include "DomainFinder.h"
using namespace std;

int main() {
	vector<GDLNode*> ast;
	try {
		Tokenizer tokenizer;
		vector<Token> tokens;
		tokenizer.tokenize("test.kif", tokens);
	
		TokenLiner tokenLiner;
		vector<TokenLine> tokenLines;
		tokenLiner.createLines(tokens, tokenLines);
		
		AST astCreator;		
		astCreator.createAST(tokenLines, ast);

		SymbolTable symbolTable;
		symbolTable.addSymbols(ast);
		DomainFinder::findDomain(ast, symbolTable);
		symbolTable.print();
	} catch (Exception &e) {
		cout << e.getMessage() << endl;
	}
	
	for (size_t i = 0; i < ast.size(); ++i) {
		delete ast[i];
	}
	
	cout << "Done!!!";
	cin.get();
	return 0;
}
