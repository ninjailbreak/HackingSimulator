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

Module::Module()
{
	this->_name = "Generic module";
	this->_version = "1.0.0";
}

Module::Module(std::string name, std::string version)	
{
	this->_name = name;
	this->_version = version;
}

Module::~Module()
{
}

std::string Module::GetProductName()
{
	return this->_name;
}

std::string Module::GetProductVersion()
{
	return this->_version;
}