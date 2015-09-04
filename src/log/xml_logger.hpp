#ifndef XML_LOGGER
#define XML_LOGGER

#include <iostream>
#include <fstream>

#include "file_logger.hpp"

class XMLLogger : public FileLogger {
	public:
		XMLLogger (const char *file_name, LogLevel &log_level);
		XMLLogger (const XMLLogger &xml_logger);
		~XMLLogger ();

		void write (LogMessage &log_message);
};

#endif