#ifndef LOGGER
#define LOGGER

#include <string>

#include "log_level.hpp"
#include "log_message.hpp"

class Logger {
	private:
		LogLevel level;

	public:
		Logger ();
		Logger (const LogLevel &level);
		Logger (const Logger &logger);
		virtual ~Logger ();

		virtual void write (LogMessage &log_message) = 0;

		LogLevel& get_level (void);
};

#endif