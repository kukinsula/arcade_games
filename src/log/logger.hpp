#ifndef LOGGER
#define LOGGER

#include <string>

#include "log_level.hpp"

class Logger {
	private:
		LogLevel level;

	public:
		Logger ();
		Logger (LogLevel level);
		virtual ~Logger ();

		virtual void write (std::string message) = 0;
		virtual void write (LogLevel level, std::string message) = 0;

		LogLevel get_level () const;
};

#endif