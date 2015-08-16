#ifndef TEST_CONTROLLER
#define TEST_CONTROLLER

#include "SDL.h"

#include "../framework/event/event_handler.hpp"
#include "../framework/event/keyboard_listener.hpp"
#include "../framework/event/widget_listener.hpp"
#include "../framework/event/mouse_listener.hpp"
#include "../framework/event/drop_file_listener.hpp"
#include "../framework/event/drag_and_drop_listener.hpp"
#include "../framework/event/window_listener.hpp"
#include "../framework/event/game_controller_listener.hpp"
#include "../framework/event/quit_listener.hpp"
#include "../framework/window/controller.hpp"

class TestController : 
	public WidgetListener,
	public KeyboardListener,
	public MouseListener,
	public WindowListener,
	public DropFileListener,
	public DragAndDropListener,
	public GameControllerListener,
	public QuitListener,
	public Controller {

	private:
		Line *line;

	public:
		TestController ();
		~TestController ();

		void on_mouse_over_widget (EventHandler *handler, Widget *widget);
		void on_left_click_on_widget (EventHandler *handler, Widget *widget);
		void on_right_click_on_widget (EventHandler *handler, Widget *widget);

		void on_key_press (EventHandler *handler, SDL_KeyboardEvent key_event);

		void on_mouse_move (EventHandler *handler, SDL_MouseMotionEvent mouse_motion_event);
		void on_mouse_button_press (EventHandler *handler, SDL_MouseButtonEvent mouse_button_event);
		void on_mouse_wheel (EventHandler *handler, SDL_MouseWheelEvent mouse_wheel_event);

		void on_window_show (EventHandler *handler, SDL_WindowEvent window_event);
		void on_window_hide (EventHandler *handler, SDL_WindowEvent window_event);
		void on_window_expose (EventHandler *handler, SDL_WindowEvent window_event);
		void on_window_move (EventHandler *handler, SDL_WindowEvent window_event);
		void on_window_resize (EventHandler *handler, SDL_WindowEvent window_event);
		void on_window_minimize (EventHandler *handler, SDL_WindowEvent window_event);
		void on_window_maximize (EventHandler *handler, SDL_WindowEvent window_event);
		void on_window_restore (EventHandler *handler, SDL_WindowEvent window_event);
		void on_window_mouse_enter (EventHandler *handler, SDL_WindowEvent window_event);
		void on_window_mouse_leave (EventHandler *handler, SDL_WindowEvent window_event);
		void on_window_focus_gain (EventHandler *handler, SDL_WindowEvent window_event);
		void on_window_focus_lost (EventHandler *handler, SDL_WindowEvent window_event);
		void on_window_close (EventHandler *handler, SDL_WindowEvent window_event);

		void on_drop_file (EventHandler *handler, SDL_DropEvent drop_event);

		void on_drag (EventHandler *handler);
		void on_dragging (EventHandler *handler);
		void on_drop (EventHandler *handler);

		void on_drag_widget (EventHandler *handler, Widget *widget);
		void on_dragging_widget (EventHandler *handler, Widget *widget);
		void on_drop_widget (EventHandler *handler, Widget *widget);
		void on_drop_on_widget (EventHandler *handler, Widget *widget);
		void on_drag_widget_over_widget (EventHandler *handler, Widget *source_widget, Widget *destination_widget);
		void on_drop_widget_on_widget (EventHandler *handler, Widget *source_widget, Widget *destination_widget);

		void on_game_controller_button_press (EventHandler *handler, SDL_ControllerButtonEvent controller_button_event);
		void on_game_controller_button_unpress (EventHandler *handler, SDL_ControllerButtonEvent controller_button_event);

		void on_game_controller_axis_motion (EventHandler *handler, SDL_ControllerAxisEvent controller_axis_event);

		void on_controller_device_added (EventHandler * handler, SDL_ControllerDeviceEvent controller_device_event);
		void on_controller_device_removed (EventHandler * handler, SDL_ControllerDeviceEvent controller_device_event);
		void on_controller_device_remapped (EventHandler * handler, SDL_ControllerDeviceEvent controller_device_event);

		void on_quit (EventHandler *handler);
};

#endif