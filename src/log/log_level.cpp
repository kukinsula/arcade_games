#include "log_level.hpp"

std::string get_level_string (LogLevel level) {
	std::string str;

	switch (level) {
		case spam:
			str = "SPAM";
			break;

		case debug:
			str = "DEBUG";
			break;

		case info:
			str = "INFO";
			break;

		case warning:
			str = "WARNING";
			break;

		case error:
			str = "ERROR";
			break;

		case critical:
			str = "CRITICAL";
			break;

		default:
			str = "";
			break;
	}

	return str;
}

std::ostream& operator<<(std::ostream &os, LogLevel level) {
	std::string str = get_level_string(level);
	os << str;

	return os;
}