#include "Symbol.h"

Symbol::Symbol(std::string name, SymbolType type, int numOfArgument) {
	this->name = name;
	this->type = type;
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

size_t Symbol::getNumOfArgument() const {
	return numOfArgument;
}

void Symbol::addArgument(size_t index, const std::string &argument) {
	argumentDomains[index].push_back(argument);
}

SymbolType Symbol::getType() const {
	return type;
}

const std::vector<std::string> &Symbol::getArgumentDomain(size_t index) const {
	return argumentDomains[index];
}