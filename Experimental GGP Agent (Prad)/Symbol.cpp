#include "Symbol.h"

Symbol::Symbol(std::string name, int numOfArgument) {
	this->name = name;
	this->numOfArgument = numOfArgument;
	if (numOfArgument > 0) {
		argumentDomains = new std::vector<std::string>[numOfArgument];
	} else {
		argumentDomains = 0;
	}
}

Symbol::~Symbol() {
	if (argumentDomains) {
		delete [] argumentDomains;
	}
}