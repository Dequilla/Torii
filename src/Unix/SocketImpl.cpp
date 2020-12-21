#ifndef _WIN32 
#include "Unix/SocketImpl.hpp"

#include <cstring>

namespace torii {
	namespace priv {

		SocketHandle SocketImpl::invalidSocket() {
			return -1;
		}

		sockaddr_in SocketImpl::createAddress(uint32_t address, uint16_t port) {
			sockaddr_in addr;
			std::memset(&addr, 0, sizeof(addr));
			addr.sin_addr.s_addr = htonl(address);
			addr.sin_family = AF_INET;
			addr.sin_port = htons(port);

			return addr;
		}

		void SocketImpl::close(SocketHandle socket) {
			::close(socket);
		}

		Socket::Status SocketImpl::getLastError() {
			if((errno == EAGAIN) || (errno == EINPROGRESS))
				return Socket::NOT_READY;

			switch (errno)
			{
				case EWOULDBLOCK:	return Socket::NOT_READY;
				case ECONNABORTED:	return Socket::DISCONNECTED;
				case ECONNRESET: 	return Socket::DISCONNECTED;
				case ETIMEDOUT:   	return Socket::DISCONNECTED;
				case ENETRESET:     	return Socket::DISCONNECTED;
				case ENOTCONN:    	return Socket::DISCONNECTED;
				case EPIPE:  		return Socket::DISCONNECTED;
				default:              	return Socket::UNEXPECTED;
			}
		}
	}
}
#endif
