#ifndef WINDOW_LISTENER
#define WINDOW_LISTENER

class EventHandler;

class WindowListener {
	public:
		virtual void on_window_show (EventHandler *handler, SDL_WindowEvent window_event);
		virtual void on_window_hide (EventHandler *handler, SDL_WindowEvent window_event);
		virtual void on_window_expose (EventHandler *handler, SDL_WindowEvent window_event);
		virtual void on_window_move (EventHandler *handler, SDL_WindowEvent window_event);
		virtual void on_window_resize (EventHandler *handler, SDL_WindowEvent window_event);
		virtual void on_window_minimize (EventHandler *handler, SDL_WindowEvent window_event);
		virtual void on_window_maximize (EventHandler *handler, SDL_WindowEvent window_event);
		virtual void on_window_restore (EventHandler *handler, SDL_WindowEvent window_event);
		virtual void on_window_mouse_enter (EventHandler *handler, SDL_WindowEvent window_event);
		virtual void on_window_mouse_leave (EventHandler *handler, SDL_WindowEvent window_event);
		virtual void on_window_focus_gain (EventHandler *handler, SDL_WindowEvent window_event);
		virtual void on_window_focus_lost (EventHandler *handler, SDL_WindowEvent window_event);
		virtual void on_window_close (EventHandler *handler, SDL_WindowEvent window_event);
};

#endif