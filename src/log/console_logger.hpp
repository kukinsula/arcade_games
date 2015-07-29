#ifndef CONSOLE_LOGGER
#define CONSOLE_LOGGER

#include "logger.hpp"

class ConsoleLogger : public Logger {
	public:
		ConsoleLogger ();
		ConsoleLogger (LogLevel level);

		void write (std::string message);
		void write (LogLevel level, std::string message);
};

#endif