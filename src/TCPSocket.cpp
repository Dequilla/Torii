#include "TCPSocket.hpp"

#include <SocketImpl.hpp>

#include <iostream>

namespace torii {

	TCPSocket::TCPSocket() :
		Socket(Socket::TCP) 
	{

	}

	Socket::Status TCPSocket::receive(void* buffer, std::size_t size, std::size_t& received) {
        received = 0;

        if (!buffer)
        {
            std::cerr << "ERROR: failed to recieve to tcp socket, buffer invalid" << std::endl;
            return Socket::UNEXPECTED;
        }

        int sizeReceived = recv(getSocketHandle(), static_cast<char*>(buffer), static_cast<int>(size), 0);

        if (sizeReceived > 0)
        {
            received = static_cast<std::size_t>(sizeReceived);
            return Socket::DONE;
        }
        else if (sizeReceived == 0)
        {
            return Socket::DISCONNECTED;
        }
        else
        {
            return priv::SocketImpl::getLastError();
        }
	}

    void TCPSocket::close() {
        Socket::close();
    }
}