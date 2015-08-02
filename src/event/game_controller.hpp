#ifndef GAME_CONTROLLER
#define GAME_CONTROLLER

#include "SDL.h"

#include "event_handler.hpp"
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

		void on_key_press (EventHandler *input, SDL_KeyboardEvent key_event);

		void on_mouse_move (EventHandler *input, SDL_MouseMotionEvent mouse_motion_event);

		void on_mouse_button_press (EventHandler *input, SDL_MouseButtonEvent mouse_button_event);

		void on_mouse_wheel (EventHandler *input, SDL_MouseWheelEvent mouse_wheel_event);

		void on_window_show (EventHandler *input, SDL_WindowEvent window_event);
		void on_window_hide (EventHandler *input, SDL_WindowEvent window_event);
		void on_window_expose (EventHandler *input, SDL_WindowEvent window_event);
		void on_window_move (EventHandler *input, SDL_WindowEvent window_event);
		void on_window_resize (EventHandler *input, SDL_WindowEvent window_event);
		void on_window_minimize (EventHandler *input, SDL_WindowEvent window_event);
		void on_window_maximize (EventHandler *input, SDL_WindowEvent window_event);
		void on_window_restore (EventHandler *input, SDL_WindowEvent window_event);
		void on_window_mouse_enter (EventHandler *input, SDL_WindowEvent window_event);
		void on_window_mouse_leave (EventHandler *input, SDL_WindowEvent window_event);
		void on_window_focus_gain (EventHandler *input, SDL_WindowEvent window_event);
		void on_window_focus_lost (EventHandler *input, SDL_WindowEvent window_event);
		void on_window_close (EventHandler *input, SDL_WindowEvent window_event);

		void on_drop_file (EventHandler *input, SDL_DropEvent drop_event);

		void on_game_controller_button_press (EventHandler *input, SDL_ControllerButtonEvent controller_button_event);
		void on_game_controller_button_unpress (EventHandler *input, SDL_ControllerButtonEvent controller_button_event);

		void on_game_controller_axis_motion (EventHandler *input, SDL_ControllerAxisEvent controller_axis_event);

		void on_controller_device_added (EventHandler * input, SDL_ControllerDeviceEvent controller_device_event);
		void on_controller_device_removed (EventHandler * input, SDL_ControllerDeviceEvent controller_device_event);
		void on_controller_device_remapped (EventHandler * input, SDL_ControllerDeviceEvent controller_device_event);

		void on_quit (EventHandler *input);
};

#endif