#include <iostream>
#include <vector>
#include "Tokenizer.h"
#include "TokenLiner.h"
#include "Exception.h"
using namespace std;

int main() {
	try {
		Tokenizer tokenizer;
		vector<Token> tokens;
		tokenizer.tokenize("test.kif", tokens);
	
		TokenLiner tokenLiner;
		vector<TokenLine> tokenLines;
		tokenLiner.createLines(tokens, tokenLines);
		tokenLiner.createLines(tokenLines[tokenLines.size() - 6].getTokens(), tokenLines);
		tokenLiner.createLines(tokenLines[tokenLines.size() - 4].getTokens(), tokenLines);
		
		for (TokenLine &tokenLine : tokenLines) {
			tokenLine.print();
		}
	} catch (Exception &e) {
		cout << e.getMessage();
	}
	
	cin.get();
	return 0;
}
