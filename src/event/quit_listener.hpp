#ifndef QUIT_LISTENER
#define QUIT_LISTENER

class EventInput;

class QuitListener {
	public:
		virtual void on_quit (EventInput *input) = 0;
};

#endif