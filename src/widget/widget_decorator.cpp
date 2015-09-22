#include "widget_decorator.hpp"

WidgetDecorator::WidgetDecorator (Widget *widget) :
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

	else {
		result = Widget::is_over(x, y);
	}

	return result;
}

bool WidgetDecorator::is_over (const Position &position) const {
	int x = position.get_x(), y = position.get_y();

	return this->is_over(x, y);
}

void WidgetDecorator::set_background_color (Color &color) {
	if (this->is_decorating() ) {
		this->original->set_background_color(color);
	}
}

void WidgetDecorator::set_window (Window *window) {
	if (this->is_decorating() ) {
		this->original->set_window(window);
		Widget::set_window(window);
	}
}

Widget* WidgetDecorator::get_original (void) const {
	return this->original;
}