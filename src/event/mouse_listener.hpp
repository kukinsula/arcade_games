#ifndef __MOUSE_LISTENER__
#define __MOUSE_LISTENER__

/**
 * @file mouse_listener.hpp
 * @version 0.1
 */

class EventHandler;

/**
 * @class MouseListener
 * @brief Listens to mouse events.
 * @see EventHandler
 *
 * MouseListeners can listen to mouse events. Subclasses should
 * register to an EventHandler and override the methods on_mouse_button_press/unpress,
 * on_mouse_move and on_mouse_wheel to be notified of mouse events.
 */
class MouseListener {
	public:
		/**
		 * @brief Constructor
		 *
		 * Constructs a MouseListener.
		 */
		MouseListener ();

		/**
		 * @brief Copy constructor
		 *
		 * Constructs a MouseListener from another MouseListener.
		 */
		MouseListener (const MouseListener &mouse_listener);

		/**
		 * @brief Destructor
		 *
		 * Destructs a MouseListener.
		 */
		~MouseListener ();

		/**
		 * @brief method called when a mouse button press event occurs
		 * @param event_handler: the EventHandler to which the MouseListener is attached to
		 * @param mouse_button_event: the SDL_MouseButtonEvent triggered
		 *
		 * MouseListeners can be notified of a mouse button press by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_mouse_button_press (EventHandler *event_handler, SDL_MouseButtonEvent mouse_button_event);
		
		/**
		 * @brief method called when a mouse button unpress event occurs
		 * @param event_handler: the EventHandler to which the MouseListener is attached to
		 * @param mouse_button_event: the SDL_MouseButtonEvent triggered
		 *
		 * MouseListeners can be notified of a mouse button unpress by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_mouse_button_unpress (EventHandler *event_handler, SDL_MouseButtonEvent mouse_button_event);

		/**
		 * @brief method called when a mouse motion press event occurs
		 * @param event_handler: the EventHandler to which the MouseListener is attached to
		 * @param mouse_motion_event: the SDL_MouseMotionEvent triggered
		 *
		 * MouseListeners can be notified of a mouse motion by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_mouse_move (EventHandler *event_handler, SDL_MouseMotionEvent mouse_motion_event);

		/**
		 * @brief method called when a mouse wheel event occurs
		 * @param event_handler: the EventHandler to which the MouseListener is attached to
		 * @param mouse_wheel_event: the SDL_MouseWheelEvent triggered
		 *
		 * MouseListeners can be notified of a mouse wheel by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_mouse_wheel (EventHandler *event_handler, SDL_MouseWheelEvent mouse_wheel_event);
};

#endif