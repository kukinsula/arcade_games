#include "mouse_over_widget_decorator.hpp"
#include "mouse_over_widget_decorator.hpp"

MouseOverWidgetDecorator::MouseOverWidgetDecorator (Widget *widget) :
	Widget(*widget),
	WidgetDecorator(widget) {}

MouseOverWidgetDecorator::MouseOverWidgetDecorator (const MouseOverWidgetDecorator &mouse_over_wiget_decorator) :
	Widget(mouse_over_wiget_decorator),
	WidgetDecorator(mouse_over_wiget_decorator) {}

MouseOverWidgetDecorator::~MouseOverWidgetDecorator () {}

void MouseOverWidgetDecorator::add_mouse_over_widget_listener (MouseOverWidgetListener *mouse_over_widget_listener) {
	this->mouse_over_widget_listeners.push_back(mouse_over_widget_listener);
}

void MouseOverWidgetDecorator::over (EventHandler *event_handler, SDL_MouseMotionEvent &mouse_motion_event) {
	for (unsigned int i = 0; i < this->mouse_over_widget_listeners.size(); i++) {
		this->mouse_over_widget_listeners[i]->on_mouse_over_widget(event_handler, this, mouse_motion_event);
	}

	if (this->is_decorating() ) {
		this->get_original()->over(event_handler, mouse_motion_event);
	}
}