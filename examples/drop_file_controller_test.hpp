#ifndef DROP_FILE_CONTROLLER_TEST
#define DROP_FILE_CONTROLLER_TEST

#include "../src/framework/window/controller.hpp"
#include "../src/framework/event/drop_file_listener.hpp"

class DropFileControllerTest :
	public Controller,
	public DropFileListener {

	public:
		void on_drop_file (EventHandler *handler, SDL_DropEvent drop_event);
};

#endif