#include "console_logger.hpp"

#include <iostream>

ConsoleLogger::ConsoleLogger () : Logger() {
}

ConsoleLogger::ConsoleLogger (LogLevel level) : Logger(level) {
}

void ConsoleLogger::write (std::string message) {
	std::cout << message << std::endl;
}

void ConsoleLogger::write (LogLevel level, std::string message) {
	std::cout << "[" << level << "] " << message << std::endl;
}