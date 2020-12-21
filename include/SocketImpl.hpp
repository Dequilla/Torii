#pragma once

#ifdef _WIN32
#include <Windows/SocketImpl.hpp>
#else
#include <Unix/SocketImpl.hpp>
#endif
