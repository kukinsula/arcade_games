#ifndef WINDOW_LISTENER
#define WINDOW_LISTENER

/**
 * @file window_listener.hpp
 * @version 0.1
 */

class EventHandler;

/**
 * @class WindowListener
 * @brief Listens to events relative to Windows.
 * @see EventHandler
 * @see Window
 *
 * WindowListeners can listen to Window events. Subclasses should register to
 * an EventHandler and override the virtual methods below to be notified of any
 * Window event.
 */
class WindowListener {
	public:
		/**
		 * @brief method called when the Window is shown
		 * @param event_handler: the EventHandler to which the WindowListener is attached to
		 * @param window_event: the SDL_WindowEvent triggered
		 */
		virtual void on_window_show (EventHandler *event_handler, SDL_WindowEvent window_event);

		/**
		 * @brief method called when the Window is hidden
		 * @param event_handler: the EventHandler to which the WindowListener is attached to
		 * @param window_event: the SDL_WindowEvent triggered
		 */
		virtual void on_window_hide (EventHandler *event_handler, SDL_WindowEvent window_event);

		/**
		 * @brief method called when the Window is exposed
		 * @param event_handler: the EventHandler to which the WindowListener is attached to
		 * @param window_event: the SDL_WindowEvent triggered
		 */
		virtual void on_window_expose (EventHandler *event_handler, SDL_WindowEvent window_event);

		/**
		 * @brief method called when the Window is moved
		 * @param event_handler: the EventHandler to which the WindowListener is attached to
		 * @param window_event: the SDL_WindowEvent triggered
		 */
		virtual void on_window_move (EventHandler *event_handler, SDL_WindowEvent window_event);

		/**
		 * @brief method called when the Window is resized
		 * @param event_handler: the EventHandler to which the WindowListener is attached to
		 * @param window_event: the SDL_WindowEvent triggered
		 */
		virtual void on_window_resize (EventHandler *event_handler, SDL_WindowEvent window_event);

		/**
		 * @brief method called when the Window is minimized
		 * @param event_handler: the EventHandler to which the WindowListener is attached to
		 * @param window_event: the SDL_WindowEvent triggered
		 */
		virtual void on_window_minimize (EventHandler *event_handler, SDL_WindowEvent window_event);

		/**
		 * @brief method called when the Window is maximized
		 * @param event_handler: the EventHandler to which the WindowListener is attached to
		 * @param window_event: the SDL_WindowEvent triggered
		 */
		virtual void on_window_maximize (EventHandler *event_handler, SDL_WindowEvent window_event);

		/**
		 * @brief method called when the Window is restored
		 * @param event_handler: the EventHandler to which the WindowListener is attached to
		 * @param window_event: the SDL_WindowEvent triggered
		 */
		virtual void on_window_restore (EventHandler *event_handler, SDL_WindowEvent window_event);

		/**
		 * @brief method called when the mouse enter the Window
		 * @param event_handler: the EventHandler to which the WindowListener is attached to
		 * @param window_event: the SDL_WindowEvent triggered
		 */
		virtual void on_window_mouse_enter (EventHandler *event_handler, SDL_WindowEvent window_event);

		/**
		 * @brief method called when the Mouse leaves the Window
		 * @param event_handler: the EventHandler to which the WindowListener is attached to
		 * @param window_event: the SDL_WindowEvent triggered
		 */
		virtual void on_window_mouse_leave (EventHandler *event_handler, SDL_WindowEvent window_event);

		/**
		 * @brief method called when the Window gains focus
		 * @param event_handler: the EventHandler to which the WindowListener is attached to
		 * @param window_event: the SDL_WindowEvent triggered
		 */
		virtual void on_window_focus_gain (EventHandler *event_handler, SDL_WindowEvent window_event);

		/**
		 * @brief method called when the Window lose focus
		 * @param event_handler: the EventHandler to which the WindowListener is attached to
		 * @param window_event: the SDL_WindowEvent triggered
		 */
		virtual void on_window_focus_lost (EventHandler *event_handler, SDL_WindowEvent window_event);

		/**
		 * @brief method called when the Window is closed
		 * @param event_handler: the EventHandler to which the WindowListener is attached to
		 * @param window_event: the SDL_WindowEvent triggered
		 */
		virtual void on_window_close (EventHandler *event_handler, SDL_WindowEvent window_event);
};

#endif