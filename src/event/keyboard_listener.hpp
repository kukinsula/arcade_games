#ifndef KEYBOARD_LISTENER
#define KEYBOARD_LISTENER

class EventHandler;

class KeyboardListener {
	public:
		virtual void on_key_press (EventHandler *handler, SDL_KeyboardEvent key_event);
		virtual void on_key_unpress (EventHandler *handler, SDL_KeyboardEvent key_event);
};

#endif