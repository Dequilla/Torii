#include "TCPListener.hpp"

#include <SocketImpl.hpp>

#include <iostream>

namespace torii {

	TCPListener::TCPListener() :
		Socket(Socket::TCP) 
	{

	}

	void TCPListener::close() {
		Socket::close();
	}

	Socket::Status TCPListener::listen(uint16_t port) {
        // Recreate socket
        close();
        create();

        // Bind the socket to the specified port
        sockaddr_in addr = priv::SocketImpl::createAddress(0, port);
        if (bind(getSocketHandle(), reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == -1)
        {
            // Not likely to happen, but...
            std::cerr << "ERROR: failed to bind tcp listener to port " << port << std::endl;
            return Socket::UNEXPECTED;
        }

        // Listen to the bound port
        if (::listen(getSocketHandle(), SOMAXCONN) == -1)
        {
            // Oops, socket is deaf
            std::cerr << "ERROR: failed to listen to port " << port << std::endl;
            return  Socket::UNEXPECTED;
        }

        return Socket::DONE;
	}

    Socket::Status TCPListener::accept(TCPSocket& socket) {
        // Make sure that we're listening
        if (getSocketHandle() == priv::SocketImpl::invalidSocket())
        {
            std::cerr << "ERROR: failed to accept new connection, socket not marked for listening" << std::endl;
            return Socket::UNEXPECTED;
        }

        sockaddr_in address;
        int length = sizeof(address);
        SocketHandle remote = ::accept(getSocketHandle(), reinterpret_cast<sockaddr*>(&address), &length);

        if (remote == priv::SocketImpl::invalidSocket())
            return priv::SocketImpl::getLastError();

        // Initialize the new connected socket
        socket.close();
        socket.create(remote);

        return Socket::DONE;
    }
}