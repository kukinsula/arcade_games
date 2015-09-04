#ifndef FILE_LOGGER
#define FILE_LOGGER

#include <iostream>
#include <fstream>

#include "logger.hpp"

class FileLogger : public Logger {
	private:
		const char *file_name;
		std::ofstream file;

	public:
		FileLogger (const char *file_name, LogLevel &log_level);
		FileLogger (const FileLogger &file_logger);
		~FileLogger ();

		void write (LogMessage &log_message);

	protected:
		std::ofstream& get_file (void);
};

#endif