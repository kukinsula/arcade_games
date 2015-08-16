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
		LogMessage ();
		LogMessage (std::string text, LogLevel level, const char* file_name, const char* function_name, unsigned int line_number);

		std::string get_text () const;
		LogLevel get_level () const;
		const char* get_file_name () const;
		const char* get_function_name () const;
		int get_line_number () const;
		int get_id () const;
};

#endif