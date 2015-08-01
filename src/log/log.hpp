#ifndef LOG
#define LOG

#include <string>
#include <vector>

#include "logger.hpp"
#include "log_level.hpp"

class Log {
	private:
		static std::vector<Logger*> loggers;

	public:
		static void add_logger (Logger *logger);

		static void write (std::string message);
		static void write (LogLevel level, std::string message);

		static void quit ();
};

#endif