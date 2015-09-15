#ifndef __FILE_LOGGER__
#define __FILE_LOGGER__

/**
 * @file file_logger.hpp
 * @version 0.1
 */

#include <iostream>
#include <fstream>

#include "logger.hpp"

/**
 * @class FileLogger
 * @brief Writes LogMessages into a specific file.
 * @see Logger
 * @see LogMessage
 *
 * FileLogger is a specialized Logger which writes
 * LogMessages into a specific file.
 */
class FileLogger : public Logger {
	private:
		const char *file_name;
		std::ofstream file;

	public:
		/**
		 * @brief Constructor
		 * @param file_name: the file name where LogMessages will be written
		 * @param log_level: the specific LogLevel
		 */
		FileLogger (const char *file_name, LogLevel &log_level);

		/**
		 * @brief Copy constructor
		 */
		FileLogger (const FileLogger &file_logger);
		
		/**
		 * @brief Destructor
		 */
		~FileLogger ();

		/**
		 * @brief Writes the LogMessage in the file
		 * @param log_message: the LogMessage to write
		 */
		void write (LogMessage &log_message);

	protected:
		/**
		 * @brief Returns the output file stream
		 * @return std::ofstream
		 *
		 * Only subclasses can use it.
		 */
		std::ofstream& get_file (void);
};

#endif