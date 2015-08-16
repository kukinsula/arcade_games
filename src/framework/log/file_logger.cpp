#include <sstream>

#include "file_logger.hpp"

FileLogger::FileLogger (const char *file_name, LogLevel log_level) :
	Logger(log_level),
	file_name(file_name) {

	this->file.open(this->file_name);
}

FileLogger::~FileLogger () {
	this->file.close();
}

void FileLogger::write (LogMessage log_message) {
	std::stringstream sstm;

	sstm <<
		log_message.get_file_name() << "::" <<
		log_message.get_function_name() << ":" <<
		log_message.get_line_number() << " [" <<
		log_message.get_level() << "] : " <<
		log_message.get_text().c_str() << "\n";

	this->file << sstm.str();
}

std::ofstream& FileLogger::get_file () {
	return this->file;
}