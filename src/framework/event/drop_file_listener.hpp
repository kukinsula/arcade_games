#ifndef DROP_FILE_LISTENER
#define DROP_FILE_LISTENER

#include "SDL.h"

#include <string>

class EventHandler;

class DropFileListener {
	private:
		std::string last_dropped_file_name;

	public:
		virtual void on_drop_file (EventHandler *handler, SDL_DropEvent drop_event) = 0;

		void set_last_dropped_file_name (std::string name);
		std::string get_last_dropped_file_name (void) const;
};

#endif