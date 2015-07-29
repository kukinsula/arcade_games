#ifndef WINDOW_LISTENER
#define WINDOW_LISTENER

class EventInput;

class WindowListener {
	public:
		virtual void on_window_show (EventInput *input, SDL_WindowEvent window_event);
		virtual void on_window_hide (EventInput *input, SDL_WindowEvent window_event);
		virtual void on_window_expose (EventInput *input, SDL_WindowEvent window_event);
		virtual void on_window_move (EventInput *input, SDL_WindowEvent window_event);
		virtual void on_window_resize (EventInput *input, SDL_WindowEvent window_event);
		virtual void on_window_minimize (EventInput *input, SDL_WindowEvent window_event);
		virtual void on_window_maximize (EventInput *input, SDL_WindowEvent window_event);
		virtual void on_window_restore (EventInput *input, SDL_WindowEvent window_event);
		virtual void on_window_mouse_enter (EventInput *input, SDL_WindowEvent window_event);
		virtual void on_window_mouse_leave (EventInput *input, SDL_WindowEvent window_event);
		virtual void on_window_focus_gain (EventInput *input, SDL_WindowEvent window_event);
		virtual void on_window_focus_lost (EventInput *input, SDL_WindowEvent window_event);
		virtual void on_window_close (EventInput *input, SDL_WindowEvent window_event);
};

#endif