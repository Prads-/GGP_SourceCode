#include <iostream>
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

void Symbol::setType(SymbolType type) {
	this->type = type;
}

std::string Symbol::getTypeStr() const {
	switch (type) {
		case SYMBOL_TYPE_ACTION:
			return "action";
		case SYMBOL_TYPE_PROPOSITION:
			return "proposition";
		case SYMBOL_TYPE_RELATION:
			return "relation";
		case SYMBOL_TYPE_RULE:
			return "rule";
	}
	return "";
}

void Symbol::print() const {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Number of arguments: " << numOfArgument << std::endl;
	std::cout << "Symbol type: " << getTypeStr() << std::endl;
	
	size_t size = 0;
	for (size_t i = 0; i < numOfArgument; ++i) {
		if (size < argumentDomains[i].size()) {
			size = argumentDomains[i].size();
		}
	}
	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < numOfArgument; ++j) {
			if (i < argumentDomains[j].size()) {
				std::cout << argumentDomains[j][i];
			} else {
				std::cout << ".";
			}
			std::cout << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "------------------------------------" << std::endl;
}

std::vector<std::string> &Symbol::getArgumentDomainModifiable(size_t index) {
	return argumentDomains[index];
}