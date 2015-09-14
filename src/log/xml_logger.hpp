#ifndef XML_LOGGER
#define XML_LOGGER

/**
 * @file xml_logger.hpp
 * @version 0.1
 */

#include <iostream>
#include <fstream>

#include "file_logger.hpp"

/**
 * @class XMLLogger
 * @brief Writes LogMessages into an XML file.
 * @see Logger
 * @see FileLogger
 * @see LogMessage
 *
 * XMLLogger is a specialized FileLogger which writes
 * LogMessages formated in an XML file.
 */
class XMLLogger : public FileLogger {
	public:
		/**
		 * @brief Constructor
		 */
		XMLLogger (const char *file_name, LogLevel &log_level);
		
		/**
		 * @brief Copy constructor
		 */
		XMLLogger (const XMLLogger &xml_logger);
		
		/**
		 * @brief Destructor
		 */
		~XMLLogger ();

		/**
		 * @brief Writes a LogMessage in the XML file
		 * @param log_message: the LogMessage to write
		 */
		void write (LogMessage &log_message);
};

#endif