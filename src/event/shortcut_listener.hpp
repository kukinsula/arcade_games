#ifndef __SHORTCUT_LISTENER__
#define __SHORTCUT_LISTENER__

/**
 * @file shortcut_listener.hpp
 * @version 0.1
 */

#include "SDL.h"

class EventHandler;

/**
 * @class ShortcutListener
 * @brief Listens to multiple keyboard pressings
 * @see EventHandler
 *
 * ShortcutListeners can listen to multiple keyboard pressings. Subclasses
 * should register to an EventHandler and override the methods on_shortcut
 * to be notified of keyboard events.
 */
class ShortcutListener {
	private:
		std::vector<SDL_Keycode> keycodes;

	public:
		/**
		 * @brief Constructor
		 */
		ShortcutListener ();
		
		/**
		 * @brief Constructor
		 * @param keycodes: the keycodes to listen to
		 */
		ShortcutListener (std::vector<SDL_Keycode> &keycodes);
		
		/**
		 * @brief Copy constructor
		 */
		ShortcutListener (const ShortcutListener &shortcut_listener);
		
		/**
		 * @brief Destructor
		 */
		~ShortcutListener ();

		/**
		 * @brief Sets the keycodes to listen to
		 * @param keycodes: the new keycodes to listen to
		 */
		void set_keycodes (std::vector<SDL_Keycode> &keycodes);

		/**
		 * @brief Returns the keycodes listened
		 * @return std::vector<SDL_KeyCode>
		 */
		std::vector<SDL_Keycode>& get_keycodes (void);

		/**
		 * @brief Method called when all the keycodes are pressed at the same time
		 * @param event_handler: the EventHandler to which the ShortcutListener is attached to
		 *
		 * ShortcutListeners can be notified of multiple key pressing by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_shortcut (EventHandler *event_handler);
};

#endif