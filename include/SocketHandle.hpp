#pragma once
#ifdef _WIN32
#include <winsock2.h>
#endif

namespace torii {

#ifdef _WIN32
	using SocketHandle = SOCKET;
#else
	using SocketHandle = int;
#endif

}
