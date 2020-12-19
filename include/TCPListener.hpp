#pragma once
#include <Types.hpp>
#include <Socket.hpp>
#include <TCPSocket.hpp>

namespace torii {

	class TCPListener : public Socket {
	public:
		TCPListener();

		void close();

		Socket::Status listen(uint16_t port);

		Socket::Status accept(TCPSocket& socket);
	};

}