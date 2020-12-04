#include "nic.hpp"

/****************
 * Constructors *
 ****************/

NetworkCard::NetworkCard(uint32_t ip, uint32_t subnet, std::string mac) : NetworkCard(ip, subnet, mac, "Generic Network Card", "1.0.0"){}

NetworkCard::NetworkCard(uint32_t ip, uint32_t subnet, std::string mac, std::string name, std::string version): Module(name, version)
{
	this->_ip = ip;
	this->_subnet = subnet;
	this->_mac = mac;
}

/****************
 * Destructors *
 ****************/

NetworkCard::~NetworkCard(){}

/*****************
 * IPs functions *
 *****************/

std::string NetworkCard::GetIPAsText() 
{
	struct in_addr ip_struct;
	ip_struct.S_un.S_addr = this->_ip;
	return inet_ntoa(ip_struct);
}

uint32_t NetworkCard::GetIPAsNum()
{
	return this->_ip;
}

/********************
 * Subnet functions *
 ********************/

std::string NetworkCard::GetSubnetAsText()
{
	struct in_addr subnet_struct;
	subnet_struct.S_un.S_addr = this->_ip;
	return inet_ntoa(subnet_struct);
}

uint32_t NetworkCard::GetSubnetAsNum()
{
	return this->_subnet;
}


/*****************
 * Mac functions *
 *****************/

std::string NetworkCard::GetMac()
{
	return this->_mac;
}

/*************************
 * Enumeration functions *
 *************************/

bool NetworkCard::IsInNetwork(uint32_t ip) 
{
	if ((this->_subnet & this->_ip) ==
		(this->_subnet & ip)) {
		return true;
	}
	return false;
}

bool NetworkCard::IsInNetwork(NetworkCard* nic) 
{
	if ((this->_subnet & this->_ip) ==
		(this->_subnet & nic->GetIPAsNum())) {
		return true;
	}
	return false;
}