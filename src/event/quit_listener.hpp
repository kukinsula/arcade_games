#ifndef QUIT_LISTENER
#define QUIT_LISTENER

class EventHandler;

class QuitListener {
	public:
		virtual void on_quit (EventHandler *event_handler) = 0;
};

#endif