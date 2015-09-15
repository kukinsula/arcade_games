#ifndef __LOGGER__
#define __LOGGER__

/**
 * @file logger.hpp
 * @version 0.1
 */

#include <string>

#include "log_level.hpp"
#include "log_message.hpp"

/**
 * @class Logger
 * @brief Allows to write LogMessages in different ways.
 * @see LogMessage
 * @see Log
 *
 * Loggers are hold by Log, they need to implement the method write in
 * order to be notified any time a LogMessage is spread.
 *
 * A Logger holds a LogLevel, it is used by Log to ignore LogMessages
 * with too low LogLevels.
 */
class Logger {
	private:
		LogLevel level;

	public:
		/**
		 * @brief Constructor
		 */
		Logger ();
		
		/**
		 * @brief Constructor
		 */
		Logger (const LogLevel &level);
		
		/**
		 * @brief Copy constructor
		 */
		Logger (const Logger &logger);

		/**
		 * @brief Destructor
		 */
		virtual ~Logger ();

		/**
		 * @brief Writes a LogMessage in a specific way.
		 *
		 * Subclasses should implement it to receive LogMessages and write them
		 * in a specific way (console, file, ...)
		 */
		virtual void write (LogMessage &log_message) = 0;

		/**
		 * @brief Returns the LogLevel of the Logger
		 * @return LogLevel
		 */
		LogLevel& get_level (void);
};

#endif