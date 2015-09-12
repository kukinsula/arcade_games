#ifndef LOG_LEVEL
#define LOG_LEVEL

#include <string>

enum LogLevel {
	spam,
	debug,
	info,
	warning,
	error,
	critical
};

std::string get_level_string (const LogLevel &level);
std::ostream& operator<<(std::ostream &os, const LogLevel &level);

#endif