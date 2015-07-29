#include "log.hpp"

std::vector<Logger*> Log::loggers;

void Log::add_logger (Logger *logger) {
	Log::loggers.push_back(logger);
}

void Log::write (std::string message) {
	for (int i = 0; (unsigned) i < Log::loggers.size(); i++) {
		Log::loggers[i]->write(message);
	}
}

void Log::write (LogLevel level, std::string message) {
	for (int i = 0; (unsigned) i < Log::loggers.size(); i++) {
		if (Log::loggers[i]->get_level() >= level) {
			Log::loggers[i]->write(level, message);
		}
	}
}

void Log::clean (void) {
	for (int i = 0; (unsigned) i < Log::loggers.size(); i++) {
		delete Log::loggers[i];
	}
}