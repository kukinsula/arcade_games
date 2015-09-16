#ifndef __LOG__
#define __LOG__

/**
 * @file log.hpp
 * @version 0.1
 */

#include <string>
#include <vector>

#include "logger.hpp"
#include "log_level.hpp"
#include "log_message.hpp"

/**
 * @class Log
 * @brief Spreads LogMessages through all Loggers.
 * @see Logger
 * @see LogMessage
 *
 * Log holds statically Loggers to which it sends all LogMessages
 * it receives: all the Loggers it holds will write the same LogMessages.
 *
 * Use the MACCRO MSG to send easily LogMessages.
 */
class Log {
	private:
		static std::vector<Logger*> loggers;

	public:
		/**
		 * @brief Register a new Logger to write LogMessages
		 * @param logger: the Logger to register
		 */
		static void add_logger (Logger *logger);

		/**
		 * @brief Makes all the Loggers write a LogMessages
		 * @param log_message: the LogMessage to send to all Loggers
		 */
		static void write (LogMessage log_message);

		/**
		 * @brief Clears all the Loggers Log holds
		 */
		static void quit (void);
};

/**
 * @brief Simple MACRO to write simple LogMessages.
 * @param LEVEL: the criticity of the LogMessage
 * @param MESSAGE: the text to write
 * @see LOG
 *
 * This MACRO helps the developper to write simple logs containing
 * only a string as text: MSG(info, "test"); MSG takes care to gather
 * all the metadata about that log.
 */
#define MSG(LEVEL, MESSAGE) \
	Log::write(LogMessage(MESSAGE, LEVEL, __FILE__,	__func__, __LINE__) );

/**
 * @brief Second MACRO to write more complexe logs
 * @param LEVEL: the criticity of the LogMessage
 * @param MESSAGE: the initial text to write
 * @see MSG
 *
 * This MACRO helps the developper to write logs containing strings
 * but also any type which has overrided the operator<< function.
 *
 * Log::write(
 *		LOG(info, "test")
 *			<< 1
 *			<< 2
 *			<< "azerty"
 *			<< true
 *			<< 'a'
 *			<< position
 *			<< color
 *			<< ... );
 */
#define LOG(LEVEL, MESSAGE) \
	LogMessage(MESSAGE, LEVEL, __FILE__, __func__, __LINE__)

#endif