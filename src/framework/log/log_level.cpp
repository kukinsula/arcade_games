#include "log_level.hpp"

std::string get_level_string (LogLevel level) {
	std::string str;

	switch (level) {
		case spam:
			str = "spam";
			break;

		case debug:
			str = "debug";
			break;

		case info:
			str = "info";
			break;

		case warning:
			str = "warning";
			break;

		case error:
			str = "error";
			break;

		case critical:
			str = "critical";
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