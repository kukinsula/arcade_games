#include "drop_file_listener.hpp"

DropFileListener::DropFileListener () {}

DropFileListener::DropFileListener (const DropFileListener &drop_file_listener) :
	last_dropped_file_name(drop_file_listener.last_dropped_file_name) {
}

DropFileListener::~DropFileListener () {}

void DropFileListener::set_last_dropped_file_name (std::string &name) {
	this->last_dropped_file_name = name;
}

std::string& DropFileListener::get_last_dropped_file_name (void) {
	return this->last_dropped_file_name;
}