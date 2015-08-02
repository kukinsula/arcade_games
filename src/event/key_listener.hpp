#ifndef KEY_LISTENER
#define KEY_LISTENER

class EventHandler;

class KeyListener {
	public:
		virtual void on_key_press (EventHandler *handler, SDL_KeyboardEvent key_event);
		virtual void on_key_unpress (EventHandler *handler, SDL_KeyboardEvent key_event);
};

#endif