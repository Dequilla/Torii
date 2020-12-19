#include "Socket.hpp"

#include <SocketImpl.hpp>

#include <iostream>

namespace torii {

	Socket::Socket(Socket::Type type) : 
		m_type(type),
		m_socket(priv::SocketImpl::invalidSocket()) 
	{

	}

	Socket::~Socket() {
		close();
	}

	void Socket::create() {
		if (m_socket == priv::SocketImpl::invalidSocket())
		{
			auto type = SOCK_STREAM;
			switch (m_type) {
			case TCP:
				type = SOCK_STREAM;
				break;
			case UDP:
				type = SOCK_DGRAM;
				break;
			}

			SocketHandle handle = socket(PF_INET, type, 0);

			if (handle == priv::SocketImpl::invalidSocket())
			{
				std::cerr << "ERROR: failed to create socket" << std::endl;
				return;
			}

			create(handle);
		}
	}

	void Socket::create(SocketHandle handle) {
		if (m_socket == priv::SocketImpl::invalidSocket())
		{
			m_socket = handle;

			if (m_type == TCP)
			{
				// Disable TCP buffering
				int yes = 1;
				if (setsockopt(m_socket, IPPROTO_TCP, TCP_NODELAY, reinterpret_cast<char*>(&yes), sizeof(yes)) == -1)
					std::cerr << "ERROR: failed to set 'TCP_NODELAY', packets will be buffered" << std::endl;
			}
			else
			{
				// Enable broadcast by default for UDP sockets
				int yes = 1;
				if (setsockopt(m_socket, SOL_SOCKET, SO_BROADCAST, reinterpret_cast<char*>(&yes), sizeof(yes)) == -1)
				{
					std::cerr << "ERROR: failed to enable broadcasting on UDP socket" << std::endl;
				}
			}
		}
	}

	void Socket::close() {
		if (m_socket != priv::SocketImpl::invalidSocket()) {
			priv::SocketImpl::close(m_socket);
			m_socket = priv::SocketImpl::invalidSocket();
		}
	}

	SocketHandle Socket::getSocketHandle() {
		return m_socket;
	}
}