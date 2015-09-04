#ifndef LOG_MESSAGE
#define LOG_MESSAGE

#include <string>

#include "log_level.hpp"

class LogMessage {
	private:
		std::string text;
		LogLevel level;
		const char* file_name;
		const char* function_name;
		unsigned int line_number;

		int id;
		static int num;

	public:
		LogMessage (std::string text, LogLevel level, const char* file_name, const char* function_name, unsigned int line_number);
		LogMessage (const LogMessage &log_message);
		~LogMessage ();

		std::string& get_text (void);
		LogLevel& get_level (void);
		const char* get_file_name (void) const;
		const char* get_function_name (void) const;
		int get_line_number (void) const;
		int get_id (void) const;
};

#endif