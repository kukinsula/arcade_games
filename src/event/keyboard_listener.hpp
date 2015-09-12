#ifndef KEYBOARD_LISTENER
#define KEYBOARD_LISTENER

/**
 * @file keyboard_listener.hpp
 * @version 0.1
 */

#include "SDL.h"

class EventHandler;

/**
 * @class KeyboardListener
 * @brief Listens to keyboard events.
 * @see EventHandler
 *
 * KeyboardListeners can listen to keyboard events. Subclasses should
 * register to an EventHandler and override the methods on_key_press or
 * on_key_unpress to be notified of keyboard events.
 */
class KeyboardListener {
	public:
		/**
		 * @brief Constructor
		 *
		 * Constructs a KeyboardListener.
		 */
		KeyboardListener ();

		/**
		 * @brief Copy constructor
		 *
		 * Constructs a KeyboardListener from another KeyboardListener.
		 */
		KeyboardListener (const KeyboardListener &keyboard_listener);

		/**
		 * @brief Destructor
		 *
		 * Destructs a KeyboardListener.
		 */
		~KeyboardListener ();

		/**
		 * @brief method called when a key press event occurs
		 * @param event_handler: the EventHandler to which the KeyboardListener is attached to
		 * @param keyboard_event: the SDL_KeyboardEvent triggered
		 *
		 * KeyboardListeners can be notified of a key press by overriding this method. They
		 * first need to register to an EventHandler.
		 */
		virtual void on_key_press (EventHandler *event_handler, SDL_KeyboardEvent keyboard_event);

		/**
		 * @brief method called when a key unpress event occurs
		 * @param event_handler: the EventHandler to which the KeyboardListener is attached to
		 * @param keyboard_event: the SDL_KeyboardEvent triggered
		 *
		 * KeyboardListeners can be notified of a key unpress by overriding this method. They
		 * first need to register to an EventHandler.
		 */
		virtual void on_key_unpress (EventHandler *event_handler, SDL_KeyboardEvent keyboard_event);
};

#endif