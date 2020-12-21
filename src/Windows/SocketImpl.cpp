#ifdef _WIN32
#include "Windows/SocketImpl.hpp"

#include <cstring>

namespace torii {
	namespace priv {

		SocketHandle SocketImpl::invalidSocket() {
			return INVALID_SOCKET;
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
			closesocket(socket);
		}

		Socket::Status SocketImpl::getLastError() {
			switch (WSAGetLastError())
			{
				case WSAEISCONN:      return Socket::DONE;
				case WSAETIMEDOUT:    return Socket::DISCONNECTED;
				case WSAECONNABORTED: return Socket::DISCONNECTED;
				case WSAECONNRESET:   return Socket::DISCONNECTED;
				case WSAENOTCONN:     return Socket::DISCONNECTED;
				case WSAENETRESET:    return Socket::DISCONNECTED;
				case WSAEWOULDBLOCK:  return Socket::NOT_READY;
				case WSAEALREADY:     return Socket::NOT_READY;
				default:              return Socket::UNEXPECTED;
			}
		}

		// We need to initialize windows sockets dll once
		// This allows it to be done automatically
		class WinSockInit {
		public:
			WinSockInit() {
				WSADATA wsaData;
				WSAStartup(MAKEWORD(2, 2), &wsaData);
			}

			~WinSockInit() {
				WSACleanup();
			}
		};
		WinSockInit socketInitializer;

	}
}
#endif
