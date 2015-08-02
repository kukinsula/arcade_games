#ifndef QUIT_LISTENER
#define QUIT_LISTENER

class EventHandler;

class QuitListener {
	public:
		virtual void on_quit (EventHandler *input) = 0;
};

#endif