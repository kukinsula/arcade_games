#ifndef MOUSE_LISTENER
#define MOUSE_LISTENER

class EventInput;

class MouseListener {
	public:
		virtual void on_mouse_button_press (EventInput *input, SDL_MouseButtonEvent mouse_button_event);
		virtual void on_mouse_button_unpress (EventInput *input, SDL_MouseButtonEvent mouse_button_event);

		virtual void on_mouse_move (EventInput *input, SDL_MouseMotionEvent mouse_motion_event);

		virtual void on_mouse_wheel (EventInput *input, SDL_MouseWheelEvent mouse_wheel_event);
};

#endif