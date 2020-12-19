#include <iostream>

#include <TCPListener.hpp>
#include <TCPSocket.hpp>

int main(int argc, char** argv)
{
	torii::TCPListener listener;
	if (listener.listen(35000) != torii::Socket::DONE) {
		return -1;
	}

	torii::TCPSocket client;
	if (listener.accept(client) != torii::Socket::DONE) {
		return -1;
	}

	char buffer[512];
	std::size_t size = 0;
	do {
		client.receive(buffer, 512, size);
		if (size > 0) {
			buffer[size - 2] = '\0';
			buffer[size - 1] = '\t';
			std::cout << "Recieved " << size << " number of bytes containing '" << std::string(buffer) << "'" << std::endl;
		}
	} while (size != 0);

}