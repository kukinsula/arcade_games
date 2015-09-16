#include "log_message.hpp"

int LogMessage::num = 0;

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

LogMessage::LogMessage (const LogMessage &log_message) :
	text(log_message.text),
	level(log_message.level),
	file_name(log_message.file_name),
	function_name(log_message.function_name),
	line_number(log_message.line_number),
	id(log_message.id) {
}

LogMessage::~LogMessage () {}

std::string& LogMessage::get_text (void) {
	return this->text;
}

LogLevel& LogMessage::get_level (void) {
	return this->level;
}

const char* LogMessage::get_file_name (void) const {
	return this->file_name;
}

const char* LogMessage::get_function_name (void) const {
	return this->function_name;
}

int LogMessage::get_line_number (void) const {
	return this->line_number;
}

int LogMessage::get_id (void) const {
	return this->id;
}