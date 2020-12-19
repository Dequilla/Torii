#pragma once
#include <Socket.hpp>

#include <cstddef>

namespace torii {

	class TCPSocket : public Socket {
	public:
		TCPSocket();

		Socket::Status receive(void* data, std::size_t size, std::size_t& received);

		void close();
	private:
		friend class TCPListener;
	};

}