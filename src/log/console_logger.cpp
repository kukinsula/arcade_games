#include "console_logger.hpp"

#include <iostream>

ConsoleLogger::ConsoleLogger () : Logger() {}

ConsoleLogger::ConsoleLogger (LogLevel level) : Logger(level) {}

ConsoleLogger::ConsoleLogger (const ConsoleLogger &console_logger) :
	Logger(console_logger) {
}

ConsoleLogger::~ConsoleLogger () {}

void ConsoleLogger::write (LogMessage &log_message) {
	std::cout <<
		log_message.get_file_name() << "::" <<
		log_message.get_function_name() << ":" <<
		log_message.get_line_number() << " [" <<
		log_message.get_level() << "] : " <<
		log_message.get_text() <<
	std::endl;
}