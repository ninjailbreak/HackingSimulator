#pragma once

#ifdef _WIN32 
#include <WinSock2.h>
#include <Windows.h>

#elif __linux__
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#endif // check system

#include <cstdint>

#include "module.hpp"

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