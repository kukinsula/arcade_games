#ifndef MOUSE_BUTTON_LISTENER
#define MOUSE_BUTTON_LISTENER

class EventInput;

class MouseButtonListener {
	public:
		virtual void on_mouse_button_press (EventInput *input, SDL_MouseButtonEvent mouse_button_event);
		virtual void on_mouse_button_unpress (EventInput *input, SDL_MouseButtonEvent mouse_button_event);
};

#endif