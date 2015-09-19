#ifndef WIDGET_CONTROLLER_TEST
#define WIDGET_CONTROLLER_TEST

#include "../src/window/controller.hpp"
#include "../src/event/drag_and_drop_widget_listener.hpp"
#include "../src/event/keyboard_listener.hpp"
#include "../src/event/shortcut_listener.hpp"
#include "../src/event/game_controller_listener.hpp"

class WidgetControllerTest :
	public Controller,
	public KeyboardListener,
	public ShortcutListener,
	public DragAndDropWidgetListener ,
	public GameControllerListener {

	private:
		Widget *selected_widget;

	public:
		WidgetControllerTest ();

		void on_mouse_over_widget (EventHandler *handler, Widget *widget);
		void on_left_click_on_widget (EventHandler *handler, Widget *widget);
		void on_right_click_on_widget (EventHandler *handler, Widget *widget);

		void on_drag_widget (EventHandler *handler, Widget *widget);
		void on_dragging_widget (EventHandler *handler, Widget *widget);
		void on_dragging_widget_over_widget (EventHandler *handler, Widget *source_widget, Widget *destination_widget);

		void on_drop_widget (EventHandler *handler, Widget *widget);
		void on_drop_on_widget (EventHandler *handler, Widget *widget);
		void on_drop_widget_on_widget (EventHandler *handler, Widget *source_widget, Widget *destination_widget);

		void on_key_press (EventHandler *handler, SDL_KeyboardEvent keyboard_event);

		void on_game_controller_button_press (EventHandler *handler, SDL_ControllerButtonEvent controller_button_event);

		void on_shortcut (EventHandler *handler);
};

#endif