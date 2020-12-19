#pragma once
#include <SocketHandle.hpp>

namespace torii {

	class Socket {
	public:
		enum Type {
			TCP,
			UDP
		};

		enum Status {
			DONE,
			NOT_READY,
			PARTIAL,
			DISCONNECTED,
			UNEXPECTED
		};

		~Socket();

	private:
		Type m_type;
		SocketHandle m_socket;

	protected:
		Socket(Type type);

		void create();

		void create(SocketHandle handle);

		void close();

		SocketHandle getSocketHandle();
	};

}