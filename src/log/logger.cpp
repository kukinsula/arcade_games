#include "logger.hpp"

Logger::Logger () :
	level(spam) {
}

Logger::Logger (const LogLevel &level) :
	level(level) {
}

Logger::Logger (const Logger &logger) :
	level(logger.level) {
}

Logger::~Logger () {}

LogLevel& Logger::get_level (void) {
	return level;
}