#ifndef __LOG_MESSAGE__
#define __LOG_MESSAGE__

/**
 * @file log_message.hpp
 * @version 0.1
 */

#include <string>
#include <sstream>

#include "log_level.hpp"

/**
 * @class LogMessage
 * @brief Holds all the metadata about a log.
 * @see Log
 * @see Loggers
 *
 * LogMessages aim to be written through Loggers. It contains metadata
 * which help the developper to debug.
 *
 * LogMessages have a unique id to identify them.
 */
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
		/**
		 * @brief Constructor
		 * @param text: the text to print
		 * @param level: the associated LogLevel to this LogMessage
		 * @param file_name: the file name from which the LogMessage was created
		 * @param function_name: the function name from which the LogMessage was created
		 * @param line_number: the line number from which the LogMessage was created
		 */
		LogMessage (std::string text, LogLevel level, const char* file_name, const char* function_name, unsigned int line_number);

		/**
		 * @brief Copy constructor
		 */
		LogMessage (const LogMessage &log_message);
		
		/**
		 * @brief Destructor
		 */
		~LogMessage ();

		/**
		 * @brief Returns the text to print
		 * @return std::string
		 */
		std::string& get_text (void);
		
		/**
		 * @brief Returns the text to print
		 * @return std::string
		 */
		LogLevel& get_level (void);

		/**
		 * @brief Returns the file name from which the LogMessage was created
		 * @return char*
		 */
		const char* get_file_name (void) const;

		/**
		 * @brief Returns the function name from which the LogMessage was created
		 * @return char*
		 */
		const char* get_function_name (void) const;

		/**
		 * @brief Returns the line number from which the LogMessage was created
		 * @return int
		 */
		int get_line_number (void) const;

		/**
		 * @brief Returns the unique id of the LogMessage
		 * @return int
		 */
		int get_id (void) const;

		/**
		 * @brief Concats any type to the LogMessage's text.
		 * @param t: any type which overrides operator<<
		 * @return LogMessage&
		 * @see LOG
		 *
		 * LogMessage behaves like an ostream so you can create more complexe
		 * logs using the operator <<. T requires to have overrided the
		 * function std::ostream& operator<< (std::ostream &os, const T &t) to
		 * be able to use it through a LogMessage.
		 */
		template<typename T>
		LogMessage& operator<< (const T &t) {
			std::stringstream ss;

			ss << t;
			this->text += ss.str();

			return *this;
		}
};

#endif