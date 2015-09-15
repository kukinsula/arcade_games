#ifndef __DROP_FILE_LISTENER__
#define __DROP_FILE_LISTENER__

/**
 * @file drop_file_listener.hpp
 * @version 0.1
 */

#include "SDL.h"

#include <string>

class EventHandler;

/**
 * @class DropFileListener
 * @brief Listens to drop file events.
 * @see Window
 * @see EventHandler
 *
 * DropFileListeners can listen to drop file events: these occur when
 * the user drags and drops a file into a Window. Subclasses should
 * register to an EventHandler and override on_drop_file method to
 * handle these events.
 */
class DropFileListener {
	private:
		std::string last_dropped_file_name;

	public:
		/**
		 * @brief Constructor
		 *
		 * Constructs a DropFileListener.
		 */
		DropFileListener ();

		/**
		 * @brief Copy constructor
		 *
		 * Constructs a DropFileListener from another DropFileListener.
		 */
		DropFileListener (const DropFileListener &drop_file_listener);

		/**
		 * @brief Destructor
		 *
		 * Destructs a DropFileListener.
		 */
		~DropFileListener ();

		/**
		 * @brief This method is called whenever a drop file event occurs
		 * @param event_handler: the EventHandler to which the DropFileListener was registered to
		 * @param drop_event: the SDL_DropEvent triggered
		 *
		 * DropFileListeners receive drop file events by overriding this method,
		 * they first need to register to an EventHandler.
		 */
		virtual void on_drop_file (EventHandler *event_handler, SDL_DropEvent drop_event) = 0;

		/**
		 * @brief Sets the last dropped file name
		 * @param name: the name of last dropped file
		 */
		void set_last_dropped_file_name (std::string &name);

		/**
		 * Returns the name of the last dropped file.
		 * @return std::string
		 */
		std::string& get_last_dropped_file_name (void);
};

#endif