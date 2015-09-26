#ifndef __EVENT_HANDLER__
#define __EVENT_HANDLER__

/**
 * @file event_handler.hpp
 * @version 0.1
 */

#include <vector>

class Window;
class Widget;

#include "../util/position.hpp"

#include "keyboard_listener.hpp"
#include "shortcut_listener.hpp"
#include "mouse_listener.hpp"
#include "window_listener.hpp"
#include "drop_file_listener.hpp"
#include "drag_and_drop_listener.hpp"
#include "game_controller_listener.hpp"
#include "quit_listener.hpp"
#include "text_input_listener.hpp"
#include "../widget/widget.hpp"
#include "keyboard.hpp"
#include "mouse.hpp"

/**
 * @class EventHandler
 * @brief Handles all the events the SDL can.
 * @see KeyboardListener
 * @see ShortcutListener
 * @see MouseListener
 * @see WindowListener
 * @see DropFileListener
 * @see DragAndDropListener
 * @see GameControllerListener
 * @see QuitListener
 * @see TextInputListener
 *
 * EventHandler handles all the events to notify its Listeners. Specific Listeners
 * can register to the EventHandler to be notified that a specific event occured.
 */
class EventHandler {
	private:
		Window *window;
		bool running;
		bool is_dragging;
		bool is_dragging_widget;
		Widget *dragged_widget;

		Keyboard keyboard;
		Mouse mouse;

		std::vector<KeyboardListener*> keyboard_listeners;
		std::vector<ShortcutListener*> shortcut_listeners;
		std::vector<MouseListener*> mouse_listeners;
		std::vector<WindowListener*> window_listeners;
		std::vector<DropFileListener*> drop_file_listeners;
		std::vector<DragAndDropListener*> drag_and_drop_listeners;
		std::vector<GameControllerListener*> game_controller_listeners;
		std::vector<QuitListener*> quit_listeners;
		std::vector<TextInputListener*> text_input_listeners;

		void keyboard_pressed (SDL_KeyboardEvent &keyboard_event);
		void keyboard_unpressed (SDL_KeyboardEvent &keyboard_event);
		void mouse_moved (SDL_MouseMotionEvent &mouse_motion_event);
		void mouse_button_pressed (SDL_MouseButtonEvent &mouse_button_event);
		void mouse_button_unpressed (SDL_MouseButtonEvent &mouse_button_event);
		void mouse_wheeled (SDL_MouseWheelEvent &mouse_wheel_event);
		void window_event (SDL_WindowEvent &window_event);
		void file_dropped (SDL_DropEvent &drop_event);
		void game_controller_button_pressed (SDL_ControllerButtonEvent &controller_button_event);
		void game_controller_button_unpressed (SDL_ControllerButtonEvent &controller_button_event);
		void game_controller_axis_motion (SDL_ControllerAxisEvent &controller_axis_event);
		void game_controller_device_added (SDL_ControllerDeviceEvent &controller_device_event);
		void game_controller_device_removed (SDL_ControllerDeviceEvent &controller_device_event);
		void game_controller_device_remapped (SDL_ControllerDeviceEvent &controller_device_event);
		void text_input (SDL_TextInputEvent &text_input_event);
		void quit (void);

	public:
		/**
		 * @brief Constructor
		 *
		 * Constructs an EventHandler.
		 */
		EventHandler (Window *window);

		/**
		 * @brief Copy constructor
		 *
		 * Constructs an EventHandler from another EventHandler.
		 */
		EventHandler (const EventHandler &event_handler);

		/**
		 * @brief Desstructor
		 *
		 * Destructs an EventHandler.
		 */
		~EventHandler ();

		/**
		 * @brief Starts the EventHandler
		 * @see EventHandler#stop
		 *
		 * The EventHandler will start to handle all the events.
		 * It will run until it is stopped.
		 */
		void start (void);

		/**
		 * @brief Stops the EventHandler
		 * @see EventHandler#start
		 *
		 * The EventHandler will stop handling all the events.
		 */
		void pause (void);

		/**
		 * @brief Registers a KeyboardListener to the EventHandler
		 * @param keyboard_listener: the KeyboardListener to register
		 */
		void add_keyboard_listener (KeyboardListener *keyboard_listener);

		/**
		 * @brief Registers a MouseListener to the EventHandler
		 * @param mouse_listener: the MouseListener to register
		 */
		void add_mouse_listener (MouseListener *mouse_listener);

		/**
		 * @brief Registers a ShortcutListener to the EventHandler
		 * @param shortcut_listener: the ShortcutListener to register
		 */
		void add_shortcut_listener (ShortcutListener *shortcut_listener);

		/**
		 * @brief Registers a WindowListener to the EventHandler
		 * @param window_listener: the WindowListener to register
		 */
		void add_window_listener (WindowListener *window_listener);

		/**
		 * @brief Registers a DropFileListener to the EventHandler
		 * @param drop_file_listener: the DropFileListener to register
		 */
		void add_drop_file_listener (DropFileListener *drop_file_listener);

		/**
		 * @brief Registers a DragAndDropListener to the EventHandler
		 * @param drag_and_drop_listener: the DragAndDropListener to register
		 */
		void add_drag_and_drop_listener (DragAndDropListener *drag_and_drop_listener);

		/**
		 * @brief Registers a GameControllerListener to the EventHandler
		 * @param game_controller_listener: the GameControllerListener to register
		 */
		void add_game_controller_listener (GameControllerListener *game_controller_listener);

		/**
		 * @brief Registers a TextInputListener to the EventHandler
		 * @param text_input_listener: the TextInputListener to register
		 */
		void add_text_input_listener (TextInputListener *text_input_listener);

		/**
		 * @brief Registers a QuitListener to the EventHandler
		 * @param quit_listener: the QuitListener to register
		 */
		void add_quit_listener (QuitListener *quit_listener);

		/**
		 * @brief Unregisters a KeyboardListener from the EventHandler
		 * @param keyboard_listener: the KeyboardListener to unregister
		 */
		void remove_keyboard_listener (KeyboardListener *keyboard_listener);

		/**
		 * @brief Unregisters a MouseListener from the EventHandler
		 * @param mouse_listener: the MouseListener to unregister
		 */
		void remove_mouse_listener (MouseListener *mouse_listener);


		/**
		 * @brief Unregisters a ShortcutListener from the EventHandler
		 * @param shortcut_listener: the ShortcutListener to unregister
		 */
		void remove_shortcut_listener (ShortcutListener *shortcut_listener);

		/**
		 * @brief Unregisters a WindowListener from the EventHandler
		 * @param window_listener: the WindowListener to unregister
		 */
		void remove_window_listener (WindowListener *window_listener);

		/**
		 * @brief Unregisters a DropFileListener from the EventHandler
		 * @param drop_file_listener: the DropFileListener to unregister
		 */
		void remove_drop_file_listener (DropFileListener *drop_file_listener);

		/**
		 * @brief Unregisters a DragAndDropListener from the EventHandler
		 * @param drag_and_drop_listener: the DragAndDropListener to unregister
		 */
		void remove_drag_and_drop_listener (DragAndDropListener *drag_and_drop_listener);

		/**
		 * @brief Unregisters a GameControllerListener from the EventHandler
		 * @param game_controller_listener: the GameControllerListener to unregister
		 */
		void remove_game_controller_listener (GameControllerListener *game_controller_listener);

		/**
		 * @brief Unregisters a TextInputListener from the EventHandler
		 * @param text_input_listener: the TextInputListener to unregister
		 */
		void remove_text_input_listener (TextInputListener *text_input_listener);
		
		/**
		 * @brief Unregisters a QuitListener from the EventHandler
		 * @param quit_listener: the QuitListener to unregister
		 */
		void remove_quit_listener (QuitListener *quit_listener);

		/**
		 * @brief Sets the EventHandler's Window it is attached to
		 * @param window: the EventHandler's Window
		 */
		void set_window (Window *window);

		/**
		 * @brief Returns the Window the EventHandler is attached to
		 * @return Window the EventHandler's Window
		 */
		Window* get_window (void) const;

		/**
		 * @brief Returns the Keyboard
		 * @return Keyboard&
		 */
		Keyboard& get_keyboard (void);
		
		/**
		 * @brief Returns the Mouse
		 * @return Mouse&
		 */
		Mouse& get_mouse (void);

		/**
		 * @brief Returns the EventHandler's running state
		 * @return true is the EventHandler is running, false otherwise
		 */
		bool is_running (void) const;
};

#include "../window/window.hpp"

#endif