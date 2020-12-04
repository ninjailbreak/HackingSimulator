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