#include "../log/log.hpp"

#include "widget_decorator.hpp"

WidgetDecorator::WidgetDecorator (Widget *widget) :
	Widget(*widget),
	original(widget) {}

WidgetDecorator::WidgetDecorator (const WidgetDecorator &widget_decorator) :
	Widget(widget_decorator),
	original(widget_decorator.original) {}

WidgetDecorator::~WidgetDecorator () {}

void WidgetDecorator::draw (void) {
	if (this->is_decorating() ) {
		this->original->draw();
	}
}

bool WidgetDecorator::is_decorating (void) const {
	return this->original != NULL;
}

bool WidgetDecorator::is_over (int x, int y) const {
	bool result = false;

	if (this->is_decorating() ) {
		result = this->original->is_over(x, y);
	}

	return result;
}

bool WidgetDecorator::is_over (const Position &position) const {
	return this->is_over(position.get_x(), position.get_y() );
}

void WidgetDecorator::set_position (Position &position) {
	if (this->is_decorating() ) {
		this->original->set_position(position);
	}

	Widget::set_position(position);
}

void WidgetDecorator::set_dimension (Dimension &dimension) {
	if (this->is_decorating() ) {
		this->set_dimension(dimension);
	}

	Widget::set_dimension(dimension);
}

void WidgetDecorator::set_background_color (Color &color) {
	if (this->is_decorating() ) {
		this->original->set_background_color(color);
	}

	Widget::set_background_color(color);
}

void WidgetDecorator::set_window (Window *window) {
	if (this->is_decorating() ) {
		this->original->set_window(window);
	}

	Widget::set_window(window);
}

void WidgetDecorator::set_parent (Widget *parent) {
	if (this->is_decorating() ) {
		this->original->set_parent(parent);
	}

	Widget::set_parent(parent);
}

Widget* WidgetDecorator::get_original (void) const {
	return this->original;
}

void WidgetDecorator::over (EventHandler *event_handler, SDL_MouseMotionEvent &mouse_motion_event) {
	if (this->is_decorating() ) {
		this->original->over(event_handler, mouse_motion_event);
	}
}

void WidgetDecorator::click (EventHandler *event_handler, SDL_MouseButtonEvent &mouse_button_event) {
	if (this->is_decorating() ) {
		this->original->click(event_handler, mouse_button_event);
	}
}