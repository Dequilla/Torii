#pragma once
#include <exception>
#include <string>

namespace torii {

	class Exception : public std::exception {
		std::string m_filename,
					m_msg;

	public:
		Exception(const std::string& msg, const std::string& file);

		const char* what() const throw ();

		const char* filename() const;
	};

}