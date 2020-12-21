#pragma once
#include <Types.hpp>
#include <Socket.hpp>
#include <SocketHandle.hpp>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <errno.h>

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
