#include <sstream>

#include "xml_logger.hpp"

XMLLogger::XMLLogger (const char *file_name, LogLevel &log_level) :
	FileLogger(file_name, log_level) {

	std::stringstream sstm;

	sstm <<
		"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" <<
		"<logs>\n";

	this->get_file() << sstm.str();
}

XMLLogger::XMLLogger (const XMLLogger &xml_logger) :
	FileLogger(xml_logger) {
}


XMLLogger::~XMLLogger () {
	std::string str("<logs>");

	this->get_file() << str;
}

void XMLLogger::write (LogMessage &log_message) {
	std::stringstream sstm;

	sstm <<
		"\t<log id=\"" <<
		log_message.get_id() << "\" level=\"" <<
		log_message.get_level() << "\" file=\"" <<
		log_message.get_file_name() << "\" function=\"" <<
		log_message.get_function_name() << "\" line=\"" <<
		log_message.get_line_number() << "\">\n\t\t" <<
		log_message.get_text().c_str() << "\t\n\t</log>\n\n";

	this->get_file() << sstm.str();
}