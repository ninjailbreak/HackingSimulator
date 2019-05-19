#pragma once
#include <string>

class Device
{
public:
	Device(std::string name);
	~Device();

protected:
	std::string _name;

};

Device::Device(std::string name)
{
	this->_name = name;
}

Device::~Device()
{
}