#ifndef WINDOW_LISTENER
#define WINDOW_LISTENER

class EventHandler;

class WindowListener {
	public:
		virtual void on_window_show (EventHandler *event_handler, SDL_WindowEvent window_event);
		virtual void on_window_hide (EventHandler *event_handler, SDL_WindowEvent window_event);
		virtual void on_window_expose (EventHandler *event_handler, SDL_WindowEvent window_event);
		virtual void on_window_move (EventHandler *event_handler, SDL_WindowEvent window_event);
		virtual void on_window_resize (EventHandler *event_handler, SDL_WindowEvent window_event);
		virtual void on_window_minimize (EventHandler *event_handler, SDL_WindowEvent window_event);
		virtual void on_window_maximize (EventHandler *event_handler, SDL_WindowEvent window_event);
		virtual void on_window_restore (EventHandler *event_handler, SDL_WindowEvent window_event);
		virtual void on_window_mouse_enter (EventHandler *event_handler, SDL_WindowEvent window_event);
		virtual void on_window_mouse_leave (EventHandler *event_handler, SDL_WindowEvent window_event);
		virtual void on_window_focus_gain (EventHandler *event_handler, SDL_WindowEvent window_event);
		virtual void on_window_focus_lost (EventHandler *event_handler, SDL_WindowEvent window_event);
		virtual void on_window_close (EventHandler *event_handler, SDL_WindowEvent window_event);
};

#endif