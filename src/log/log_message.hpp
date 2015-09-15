#ifndef LOG_MESSAGE
#define LOG_MESSAGE

/**
 * @file log_message.hpp
 * @version 0.1
 */

#include <string>
 #include <sstream>

#include "log_level.hpp"

/**
 * @class LogMessage
 * @brief Holds all the metadata about a log to be written through Loggers.
 * @see Log
 * @see Loggers
 *
 * LogMessages will be written through Loggers. It contains metadata
 * which help the developper.
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
		 * @brief 
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