#ifndef KEY_LISTENER
#define KEY_LISTENER

class EventInput;

class KeyListener {
	public:
		virtual void on_key_press (EventInput *input, SDL_KeyboardEvent key_event);
		virtual void on_key_unpress (EventInput *input, SDL_KeyboardEvent key_event);
};

#endif