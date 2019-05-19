#pragma once

#ifdef _WIN32 
#include <WinSock2.h>

#elif __linux__
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#endif // check system

#include "module.h"

class NetworkCard: public Module
{
public:
	NetworkCard(uint32_t ip, uint32_t subnet, std::string mac);
	NetworkCard(uint32_t ip, uint32_t subnet, std::string mac, std::string name, std::string version);
	~NetworkCard();

	std::string GetIPAsText();
	uint32_t GetIPAsNum();
	
	std::string GetMac();

	std::string GetSubnetAsText();
	uint32_t GetSubnetAsNum();

	bool IsInNetwork(uint32_t ip);
	bool IsInNetwork(NetworkCard* nic);

private:
	uint32_t _ip;
	uint32_t _subnet;
	std::string _mac;
};

NetworkCard::NetworkCard(uint32_t ip, uint32_t subnet, std::string mac) : NetworkCard(ip, subnet, mac, "Generic Network Card", "1.0.0"){}

NetworkCard::NetworkCard(uint32_t ip, uint32_t subnet, std::string mac, std::string name, std::string version): Module(name, version)
{
	this->_ip = ip;
	this->_subnet = subnet;
	this->_mac = mac;
}

NetworkCard::~NetworkCard(){}


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

std::string NetworkCard::GetMac()
{
	return this->_mac;
}

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