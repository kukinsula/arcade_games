#ifndef GAME_CONTROLLER
#define GAME_CONTROLLER

#include "SDL.h"

#include "event_input.hpp"
#include "key_listener.hpp"
#include "mouse_listener.hpp"
#include "drop_file_listener.hpp"
#include "window_listener.hpp"
#include "game_controller_listener.hpp"
#include "quit_listener.hpp"

class GameController : 
	public KeyListener,
	public MouseListener,
	public WindowListener,
	public DropFileListener,
	public GameControllerListener,
	public QuitListener {

	public:
		GameController ();
		~GameController ();

		void on_key_press (EventInput *input, SDL_KeyboardEvent key_event);

		void on_mouse_move (EventInput *input, SDL_MouseMotionEvent mouse_motion_event);

		void on_mouse_button_press (EventInput *input, SDL_MouseButtonEvent mouse_button_event);

		void on_mouse_wheel (EventInput *input, SDL_MouseWheelEvent mouse_wheel_event);

		void on_window_show (EventInput *input, SDL_WindowEvent window_event);
		void on_window_hide (EventInput *input, SDL_WindowEvent window_event);
		void on_window_expose (EventInput *input, SDL_WindowEvent window_event);
		void on_window_move (EventInput *input, SDL_WindowEvent window_event);
		void on_window_resize (EventInput *input, SDL_WindowEvent window_event);
		void on_window_minimize (EventInput *input, SDL_WindowEvent window_event);
		void on_window_maximize (EventInput *input, SDL_WindowEvent window_event);
		void on_window_restore (EventInput *input, SDL_WindowEvent window_event);
		void on_window_mouse_enter (EventInput *input, SDL_WindowEvent window_event);
		void on_window_mouse_leave (EventInput *input, SDL_WindowEvent window_event);
		void on_window_focus_gain (EventInput *input, SDL_WindowEvent window_event);
		void on_window_focus_lost (EventInput *input, SDL_WindowEvent window_event);
		void on_window_close (EventInput *input, SDL_WindowEvent window_event);

		void on_drop_file (EventInput *input, SDL_DropEvent drop_event);

		void on_game_controller_button_press (EventInput *input, SDL_ControllerButtonEvent controller_button_event);
		void on_game_controller_button_unpress (EventInput *input, SDL_ControllerButtonEvent controller_button_event);

		void on_game_controller_axis_motion (EventInput *input, SDL_ControllerAxisEvent controller_axis_event);

		void on_controller_device_added (EventInput * input, SDL_ControllerDeviceEvent controller_device_event);
		void on_controller_device_removed (EventInput * input, SDL_ControllerDeviceEvent controller_device_event);
		void on_controller_device_remapped (EventInput * input, SDL_ControllerDeviceEvent controller_device_event);

		void on_quit (EventInput *input);
};

#endif