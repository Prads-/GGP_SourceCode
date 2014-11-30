#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token {
private:
	std::string tokenStr;
	int type;
	
public:
	Token() { }
	Token(std::string tokenStr, int type);
	
	std::string getTokenStr() const;
	int getType() const;
	
	std::string getTypeString() const;
	void print(bool typeString = true, bool newline = true) const;
};

#endif
