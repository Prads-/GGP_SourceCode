#ifndef VAR_TABLE_H
#define VAR_TABLE_H

#include <string>
#include <unordered_map>
#include <vector>

class VarAddress {
private:
	std::string propName;
	size_t index;
	
public:
	VarAddress(std::string propName, size_t index);
	
	std::string getPropName() const;
	size_t getIndex() const;
};

class Variable {
private:
	std::string name;
	std::vector<VarAddress> addresses;
	
public:
	Variable(std::string name);
	
	std::string getName() const;
	const std::vector<VarAddress> &getAddresses() const;
	
	void addAddress(VarAddress address);
};

typedef std::unordered_map<std::string, Variable> VarTable;

#endif
