#ifndef WIDGET_CONTROLLER_TEST
#define WIDGET_CONTROLLER_TEST

#include "../src/framework/window/controller.hpp"
#include "../src/framework/event/widget_listener.hpp"
#include "../src/framework/event/keyboard_listener.hpp"

class WidgetControllerTest :
	public Controller,
	public KeyboardListener,
	public WidgetListener {

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
};

#endif