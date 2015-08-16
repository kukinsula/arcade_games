#include "log_message.hpp"

int LogMessage::num = 0;

#include <stdio.h>
LogMessage::LogMessage (
	std::string text,
	LogLevel level,
	const char* file_name,
	const char* function_name,
	unsigned int line_number) :

	text(text),
	level(level),
	file_name(file_name),
	function_name(function_name),
	line_number(line_number),
	id(++LogMessage::num) {
}

std::string LogMessage::get_text () const {
	return this->text;
}

LogLevel LogMessage::get_level () const {
	return this->level;
}

const char* LogMessage::get_file_name () const {
	return this->file_name;
}

const char* LogMessage::get_function_name () const {
	return this->function_name;
}

int LogMessage::get_line_number () const {
	return this->line_number;
}

int LogMessage::get_id () const {
	return this->id;
}

// std::ostream& operator<<(std::ostream& os, const LogMessage &log_message) {
	// std::stringstream sstm;

	// os << 

	// return os;
// }