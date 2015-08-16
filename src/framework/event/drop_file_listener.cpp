#include "drop_file_listener.hpp"

void DropFileListener::set_last_dropped_file_name (std::string name) {
	this->last_dropped_file_name = name;
}

std::string DropFileListener::get_last_dropped_file_name (void) const {
	return this->last_dropped_file_name;
}