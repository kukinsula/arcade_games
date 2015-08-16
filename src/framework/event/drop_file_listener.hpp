#ifndef DROP_FILE_LISTENER
#define DROP_FILE_LISTENER

class EventHandler;

class DropFileListener {
	public:
		virtual void on_drop_file (EventHandler *handler, SDL_DropEvent drop_event) = 0;
};

#endif