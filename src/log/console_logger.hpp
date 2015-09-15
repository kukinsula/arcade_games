#ifndef __CONSOLE_LOGGER__
#define __CONSOLE_LOGGER__

/**
 * @file console_logger.hpp
 * @version 0.1
 */

#include "logger.hpp"

/**
 * @class ConsoleLogger
 * @brief Writes LogMessages into the console.
 * @see Logger
 * @see LogMessage
 *
 * ConsoleLogger is a specialized Logger which writes
 * LogMessages into the console.
 */
class ConsoleLogger : public Logger {
	public:
		/**
		 * @brief Constructor
		 */
		ConsoleLogger ();

		/**
		 * @brief Copy constructor
		 */
		ConsoleLogger (const ConsoleLogger &console_logger);

		/**
		 * @brief Constructor with a specific LogLevel
		 * @param level: the specific LogLevel
		 */
		ConsoleLogger (LogLevel level);

		/**
		 * @brief Destructor
		 */
		~ConsoleLogger ();

		/**
		 * @brief Writes log_message into the console
		 * @param log_message: the LogMessage to write
		 */
		void write (LogMessage &log_message);
};

#endif