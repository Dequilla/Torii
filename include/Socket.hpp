#pragma once
#include <vector>

#include <Types.hpp>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

#pragma comment(lib, "Ws2_32.lib")
#endif

#ifdef _WIN32
#define SocketDescriptor SOCKET
#endif

namespace torii {

	class Connection {
		uint16_t m_port;
		SocketDescriptor m_clientSocket;
		std::vector<int8_t> m_buffer;

	public:
		Connection(uint16_t port, SocketDescriptor clientSocket);
		~Connection();

		std::vector<int8_t> recieve();
	};

	class Socket {
#ifdef _WIN32
		SocketDescriptor m_socket;
#endif

		uint16_t m_port;

	public:
		Socket(uint16_t port);
		~Socket();

		void listen();
		Connection accept();
	};

}