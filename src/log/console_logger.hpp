#ifndef CONSOLE_LOGGER
#define CONSOLE_LOGGER

#include "logger.hpp"

class ConsoleLogger : public Logger {
	public:
		ConsoleLogger ();
		ConsoleLogger (const ConsoleLogger &console_logger);
		ConsoleLogger (LogLevel level);
		~ConsoleLogger ();

		void write (LogMessage &log_message);
};

#endif