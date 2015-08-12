#ifndef MOUSE_LISTENER
#define MOUSE_LISTENER

class EventHandler;

class MouseListener {
	public:
		virtual void on_mouse_button_press (EventHandler *handler, SDL_MouseButtonEvent mouse_button_event);
		virtual void on_mouse_button_unpress (EventHandler *handler, SDL_MouseButtonEvent mouse_button_event);

		virtual void on_mouse_move (EventHandler *handler, SDL_MouseMotionEvent mouse_motion_event);

		virtual void on_mouse_wheel (EventHandler *handler, SDL_MouseWheelEvent mouse_wheel_event);
};

#endif