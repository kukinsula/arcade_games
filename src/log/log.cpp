#include "log.hpp"

std::vector<Logger*> Log::loggers;

void Log::add_logger (Logger *logger) {
	Log::loggers.push_back(logger);
}

void Log::write (LogMessage log_message) {
	for (int i = 0; (unsigned) i < Log::loggers.size(); i++) {
		if (Log::loggers[i]->get_level() >= log_message.get_level() ) {
			Log::loggers[i]->write(log_message);
		}
	}
}

void Log::quit (void) {
	for (int i = 0; (unsigned) i < Log::loggers.size(); i++) {
		delete Log::loggers[i];
	}
}