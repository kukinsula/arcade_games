#ifndef CONSOLE_LOGGER
#define CONSOLE_LOGGER

#include "logger.hpp"

class ConsoleLogger : public Logger {
	public:
		ConsoleLogger ();
		ConsoleLogger (LogLevel level);

		void write (LogMessage log_message);
};

#endif