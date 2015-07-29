#ifndef EVENT_INPUT
#define EVENT_INPUT

#include <vector>

#include "key_listener.hpp"
#include "mouse_motion_listener.hpp"
#include "mouse_button_listener.hpp"
#include "window_listener.hpp"
#include "quit_listener.hpp"

class EventInput {
	private:
		const Uint8 *keys;
		int mouse_x, mouse_y;
		int mouse_x_rel, mouse_y_rel;
		char mouse_buttons[8];
		bool has_quit;

		std::vector<KeyListener*> key_listeners;
		std::vector<MouseMotionListener*> mouse_motion_listeners;
		std::vector<MouseButtonListener*> mouse_button_listeners;
		std::vector<WindowListener*> window_listeners;
		std::vector<QuitListener*> quit_listeners;

		void key_press (SDL_KeyboardEvent key_event);
		void key_unpress (SDL_KeyboardEvent key_event);
		void mouse_move (SDL_MouseMotionEvent mouse_motion_event);
		void mouse_button_press (SDL_MouseButtonEvent mouse_button_event);
		void mouse_button_unpress (SDL_MouseButtonEvent mouse_button_event);
		void window (SDL_WindowEvent window_event);
		void quit ();

	public:
		EventInput ();
		~EventInput ();

		void update ();

		void add_key_listener (KeyListener *key_listener);
		void add_mouse_motion_listener (MouseMotionListener *key_listener);
		void add_mouse_button_listener (MouseButtonListener *mouse_button_listener);
		void add_window_listener (WindowListener *window_listener);
		void add_quit_listener (QuitListener *quit_listener);

		void remove_key_listener (KeyListener *key_listener);
		void remove_mouse_motion_listener (MouseMotionListener *mouse_motion_listener);
		void remove_mouse_button_listener (MouseButtonListener *mouse_button_listener);
		void remove_window_listener (WindowListener *window_listener);
		void remove_quit_listener (QuitListener *quit_listener);

		bool is_key_down (SDL_Keycode key) const;
		bool is_key_up (SDL_Keycode key) const;

		int get_mouse_x () const;
		int get_mouse_y () const;
		int get_mouse_x_rel () const;
		int get_mouse_y_rel () const;

		bool has_quitted () const;
};

#endif