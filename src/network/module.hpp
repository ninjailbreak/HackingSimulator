#pragma once
#include <string>

class Module
{
public:
	Module();
	Module(std::string name, std::string version);
	~Module();
	std::string GetProductName();
	std::string GetProductVersion();

private:
	std::string _name;
	std::string _version;
};