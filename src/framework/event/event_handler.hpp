#ifndef EVENT_HANDLER
#define EVENT_HANDLER

#include <vector>

class Window;

#include "../util/position.hpp"
#include "keyboard_listener.hpp"
#include "mouse_listener.hpp"
#include "window_listener.hpp"
#include "drop_file_listener.hpp"
#include "drag_and_drop_listener.hpp"
#include "game_controller_listener.hpp"
#include "quit_listener.hpp"
#include "../widget/widget.hpp"

class EventHandler {
	private:
		Window *window;
		const Uint8 *keys;
		int mouse_x, mouse_y;
		int mouse_x_rel, mouse_y_rel;
		char mouse_buttons[8];
		bool running;
		bool is_dragging;
		bool is_dragging_widget;
		Widget *dragged_widget;

		std::vector<KeyboardListener*> keyboard_listeners;
		std::vector<MouseListener*> mouse_listeners;
		std::vector<WindowListener*> window_listeners;
		std::vector<DropFileListener*> drop_file_listeners;
		std::vector<DragAndDropListener*> drag_and_drop_listeners;
		std::vector<GameControllerListener*> game_controller_listeners;
		std::vector<QuitListener*> quit_listeners;

		void keyboard_pressed (SDL_KeyboardEvent key_event);
		void keyboard_unpressed (SDL_KeyboardEvent key_event);
		void mouse_moved (SDL_MouseMotionEvent mouse_motion_event);
		void mouse_button_pressed (SDL_MouseButtonEvent mouse_button_event);
		void mouse_button_unpressed (SDL_MouseButtonEvent mouse_button_event);
		void mouse_wheeled (SDL_MouseWheelEvent mouse_wheel_event);
		void window_event (SDL_WindowEvent window_event);
		void file_dropped (SDL_DropEvent drop_event);
		void game_controller_button_pressed (SDL_ControllerButtonEvent controller_button_event);
		void game_controller_button_unpressed (SDL_ControllerButtonEvent controller_button_event);
		void game_controller_axis_motion (SDL_ControllerAxisEvent controller_axis_event);
		void game_controller_device_added (SDL_ControllerDeviceEvent controller_device_event);
		void game_controller_device_removed (SDL_ControllerDeviceEvent controller_device_event);
		void game_controller_device_remapped (SDL_ControllerDeviceEvent controller_device_event);
		void quit ();

	public:
		EventHandler (Window *window);
		EventHandler (const EventHandler &event_handler);
		~EventHandler ();

		void start ();
		void pause ();

		void add_keyboard_listener (KeyboardListener *keyboard_listener);
		void add_mouse_listener (MouseListener *mouse_listener);
		void add_window_listener (WindowListener *window_listener);
		void add_drop_file_listener (DropFileListener *drop_file_listener);
		void add_drag_and_drop_listener (DragAndDropListener *drag_and_drop_listener);
		void add_game_controller_listener (GameControllerListener *game_controller_listener);
		void add_quit_listener (QuitListener *quit_listener);

		void remove_keyboard_listener (KeyboardListener *keyboard_listener);
		void remove_mouse_listener (MouseListener *mouse_listener);
		void remove_window_listener (WindowListener *window_listener);
		void remove_drop_file_listener (DropFileListener *drop_file_listener);
		void remove_drag_and_drop_listener (DragAndDropListener *drag_and_drop_listener);
		void remove_game_controller_listener (GameControllerListener *game_controller_listener);
		void remove_quit_listener (QuitListener *quit_listener);

		bool is_key_down (SDL_Keycode key) const;
		bool is_key_up (SDL_Keycode key) const;

		void set_window (Window *window);

		int get_mouse_x (void) const;
		int get_mouse_y (void) const;
		int get_mouse_x_rel (void) const;
		int get_mouse_y_rel (void) const;
		Window* get_window (void) const;

		bool is_running () const;
};

#include "../window/window.hpp"

#endif