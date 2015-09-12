#ifndef QUIT_LISTENER
#define QUIT_LISTENER

/**
 * @file quit_listener.hpp
 * @version 0.1
 */

class EventHandler;

/**
 * @class QuitListener
 * @brief Listens to quit events.
 * @see EventHandler
 *
 * QuitListeners can listen to quit events: these occur when the user close a Window.
 * Subclasses should register to an EventHandler and override the method on_quit to be
 * notified of quit events.
 */
class QuitListener {
	public:
		/**
		 * @brief method called when a quit event occurs
		 * @param event_handler: the EventHandler to which the QuitListener is attached to
		 *
		 * QuitListeners can be notified of a quit event by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_quit (EventHandler *event_handler) = 0;
};

#endif