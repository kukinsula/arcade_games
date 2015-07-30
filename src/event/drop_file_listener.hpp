#ifndef DROP_FILE_LISTENER
#define DROP_FILE_LISTENER

class EventInput;

class DropFileListener {
	public:
		virtual void on_drop_file (EventInput *input, SDL_DropEvent drop_event) = 0; 
};

#endif