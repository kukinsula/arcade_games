#ifndef BIG_CONTROLLER
#define BIG_CONTROLLER

/**
 * @file big_controller.hpp
 * @version 0.1
 */

#include "controller.hpp"
#include "../event/drag_and_drop_listener.hpp"
#include "../event/drop_file_listener.hpp"
#include "../event/game_controller_listener.hpp"
#include "../event/keyboard_listener.hpp"
#include "../event/mouse_listener.hpp"
#include "../event/quit_listener.hpp"
#include "../event/widget_listener.hpp"
#include "../event/window_listener.hpp"

/**
 * @class BigController
 * @brief Big controller which can listen to all events
 * @see Controller
 * @see Window
 * @see View
 *
 * BigController is a shortcut for developpers: they can simply
 * inherit from it and be able to handle all kind of events.
 */
class BigController :
	public Controller,
	public DragAndDropListener,
	public DropFileListener,
	public GameControllerListener,
	public KeyboardListener,
	public MouseListener,
	public QuitListener,
	public WidgetListener,
	public WindowListener {

	public:
		/**
		 * @brief Constructor
		 */
		BigController ();
		
		/**
		 * @brief Copy constructor
		 */
		BigController (const BigController &big_controller);
		
		/**
		 * @brief Destructor
		 */
		~BigController ();

		virtual void on_drop_file (EventHandler *handler, SDL_DropEvent drop_event);

		virtual void on_quit (EventHandler *handler);
};

#endif