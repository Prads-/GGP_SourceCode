#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

class Exception : public std::exception {
private:
	std::string message;
	
public:
	Exception(std::string message) : message(message) { }
	
	std::string getMessage() { return message; }
};

#endif