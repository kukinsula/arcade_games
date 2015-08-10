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
		Logger (LogLevel level);
		virtual ~Logger ();

		virtual void write (LogMessage log_message) = 0;

		LogLevel get_level () const;
};

#endif