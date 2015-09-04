#ifndef DROP_FILE_LISTENER
#define DROP_FILE_LISTENER

#include "SDL.h"

#include <string>

class EventHandler;

class DropFileListener {
	private:
		std::string last_dropped_file_name;

	public:
		DropFileListener ();
		DropFileListener (const DropFileListener &drop_file_listener);
		~DropFileListener ();

		virtual void on_drop_file (EventHandler *event_handler, SDL_DropEvent drop_event) = 0;

		void set_last_dropped_file_name (std::string &name);
		std::string& get_last_dropped_file_name (void);
};

#endif