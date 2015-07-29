#include "logger.hpp"

Logger::Logger () {
	this->level = spam;
}

Logger::Logger (LogLevel level) : level(level) {
}

Logger::~Logger () {
}

LogLevel Logger::get_level () const {
	return level;
}