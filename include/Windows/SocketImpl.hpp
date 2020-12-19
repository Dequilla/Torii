#pragma once
#include <Types.hpp>
#include <Socket.hpp>
#include <SocketHandle.hpp>

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

#pragma comment(lib, "Ws2_32.lib")

namespace torii {
	namespace priv {

		class SocketImpl {
		public:
			static SocketHandle invalidSocket();
			
			// IPv4
			static sockaddr_in createAddress(uint32_t address, uint16_t port);

			static void close(SocketHandle socket);

			static Socket::Status getLastError();
		};

	}
}