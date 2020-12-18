#include <string>
#include <iostream>

#include "Socket.hpp"

int main(int argc, char** argv)
{
    torii::Socket socket(35000);
    socket.listen();

	// Receive until the peer shuts down the connection
	std::vector<torii::int8_t> recieved;
	do {
		torii::Connection connection = socket.accept();
		recieved = connection.recieve();
		for (auto chr : recieved) {
			std::cout << chr;
		}
		std::cout << std::endl;
	} while (recieved.size() > 0);
}