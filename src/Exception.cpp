#include "Exception.hpp"

torii::Exception::Exception(const std::string& msg, const std::string& file)
	: m_msg(msg), m_filename(file) {

}

const char* torii::Exception::what() const throw () {
	return std::string("Torii: error in ")
			.append(m_filename)
			.append(" - ")
			.append(m_msg)
			.c_str();
}

const char* torii::Exception::filename() const {
	return m_filename.c_str();
}