#ifndef LOG
#define LOG

#include <string>
#include <vector>

#include "logger.hpp"
#include "log_level.hpp"
#include "log_message.hpp"

class Log {
	private:
		static std::vector<Logger*> loggers;

	public:
		static void add_logger (Logger *logger);
		static void write (LogMessage log_message);
		static void quit (void);
};

#define MSG(LEVEL, MESSAGE) \
	Log::write(LogMessage(MESSAGE, LEVEL, __FILE__,	__func__, __LINE__) );

#endif