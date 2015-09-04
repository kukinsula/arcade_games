#ifndef MOUSE_LISTENER
#define MOUSE_LISTENER

class EventHandler;

class MouseListener {
	public:
		MouseListener ();
		MouseListener (const MouseListener &mouse_listener);
		~MouseListener ();

		virtual void on_mouse_button_press (EventHandler *event_handler, SDL_MouseButtonEvent mouse_button_event);
		virtual void on_mouse_button_unpress (EventHandler *event_handler, SDL_MouseButtonEvent mouse_button_event);

		virtual void on_mouse_move (EventHandler *event_handler, SDL_MouseMotionEvent mouse_motion_event);

		virtual void on_mouse_wheel (EventHandler *event_handler, SDL_MouseWheelEvent mouse_wheel_event);
};

#endif