#ifndef LOG_LEVEL
#define LOG_LEVEL

/**
 * @file log.hpp
 * @version 0.1
 */

#include <string>

/**
 * LogLevel defines the criticity of a LogMessage.
 */
enum LogLevel {
	spam, /**< SPAM LogLevel */
	debug, /**< DEBUG LogLevel */
	info, /**< INFO LogLevel */
	warnin /**< WARNING LogLevelg */
	error, /**< ERROR LogLevel */
	critical /**< CRITICAL LogLevel */
};

/**
 * @brief Returns a string representation of a LogLevel
 * @param level: the LogLevel to convert
 */
std::string get_level_string (const LogLevel &level);

/**
 * @brief Writes a LogLevel into an ostream
 * @param os: the ostream in which to write
 * @param level: the LogLevel to write
 */
std::ostream& operator<<(std::ostream &os, const LogLevel &level);

#endif