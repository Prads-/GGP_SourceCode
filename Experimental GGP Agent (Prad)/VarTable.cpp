#include "VarTable.h"

VarAddress::VarAddress(std::string propName, size_t index) {
	this->propName = propName;
	this->index = index;
}
	
std::string VarAddress::getPropName() const {
	return propName;
}

size_t VarAddress::getIndex() const {
	return index;
}

Variable::Variable(std::string name) {
	this->name = name;
}
	
std::string Variable::getName() const {
	return name;
}

const std::vector<VarAddress> &Variable::getAddresses() const {
	return addresses;
}

void Variable::addAddress(VarAddress address) {
	addresses.push_back(address);
}