#include "Socket.hpp"

#include <Exception.hpp>

torii::Connection::Connection(uint16_t port, SocketDescriptor clientSocket) 
	: m_port(port), m_clientSocket(clientSocket) {
	m_buffer.reserve(512);
}

torii::Connection::~Connection() {
#ifdef _WIN32
	closesocket(m_clientSocket);
#endif;
}

std::vector<torii::int8_t> torii::Connection::recieve() {
	memset(&m_buffer[0], '\0', m_buffer.size());

#ifdef _WIN32 
	torii::int32_t recieved = 0;
	recieved = recv(m_clientSocket, &m_buffer[0], 512, 0);
	if (recieved >= 0) {
		return m_buffer;
	} else {
		closesocket(m_clientSocket);
		WSACleanup();

		throw Exception(
			std::string("Socket with port ")
				.append(std::to_string(m_port))
				.append(" could not recieve (recv)"),
			__FILE__
		);
	}
#endif
}

torii::Socket::Socket(uint16_t port)
	: m_port(port)
{
#ifdef _WIN32
	WSADATA wsaData;
	
	// Initialize Winsock
	int ec = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (ec != 0) {
		throw Exception(
			std::string("Socket with port ")
				.append(std::to_string(m_port))
				.append(" failed to initialize WSAStartup, error code ")
				.append(std::to_string(ec)),
			__FILE__
		);
	}

	// Setup before creating socket
	addrinfo *result = nullptr, 
			 *ptr = nullptr,
			 hints;

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	// Resolve the local address and port to be used by the server
	ec = getaddrinfo(NULL, std::to_string(m_port).c_str(), &hints, &result);
	if (ec != 0) {
		throw Exception(
			std::string("Socket with port ")
				.append(std::to_string(m_port))
				.append(" failed to getaddrinfo, error code ")
				.append(std::to_string(ec)),
			__FILE__
		);
	}

	m_socket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (m_socket == INVALID_SOCKET) {
		freeaddrinfo(result);

		throw Exception(
			std::string("Socket with port ")
				.append(std::to_string(m_port))
				.append(" failed to be created"),
			__FILE__
		);
	}

	// Setup the TCP listening socket
	ec = bind(m_socket, result->ai_addr, (int)result->ai_addrlen);
	if (ec == SOCKET_ERROR) {
		closesocket(m_socket);
		freeaddrinfo(result);
		
		throw Exception(
			std::string("Socket with port ")
				.append(std::to_string(m_port))
				.append(" failed to be bound"),
			__FILE__
		);
	}

	freeaddrinfo(result);
#endif
}

torii::Socket::~Socket() {
#ifdef _WIN32
	WSACleanup();
#endif
}

void torii::Socket::listen() {
#ifdef _WIN32
	if (::listen(m_socket, SOMAXCONN) == SOCKET_ERROR) {
		closesocket(m_socket);
		WSACleanup();

		throw Exception(
			std::string("Socket with port ")
				.append(std::to_string(m_port))
				.append(" could not start listening"),
			__FILE__
		);
	}
#endif
}

torii::Connection torii::Socket::accept() {
#ifdef _WIN32
	// Accept a client socket
	SocketDescriptor clientSocket = INVALID_SOCKET;
	clientSocket = ::accept(m_socket, NULL, NULL);
	if (clientSocket == INVALID_SOCKET) {
		closesocket(m_socket);
		WSACleanup();

		throw Exception(
			std::string("Socket with port ")
				.append(std::to_string(m_port))
				.append(" could not accept the client socket"),
			__FILE__
		);
	}

	return Connection(
		m_port,
		clientSocket
	);
#endif
}
