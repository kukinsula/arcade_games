#include "../log/log.hpp"

#include "button.hpp"

Button::Button (std::string text) :
	Label(text),
	WidgetDecorator(NULL) {}

Button::Button (Widget *widget) :
	Label(""),
	WidgetDecorator(widget) {}

Button::Button (Label *label) :
	Label(*label),
	WidgetDecorator(label) {}

Button::Button (std::string text, Widget *widget) :
	Label(text),
	WidgetDecorator(widget) {}

Button::Button (int x, int y, int width, int height, std::string text) :
	Label(x, y, width, height, text),
	WidgetDecorator(NULL) {}

Button::Button (Position position, Dimension dimension, std::string text) :
	Label(position, dimension, text),
	WidgetDecorator(NULL) {}

Button::Button (const Button &button) :
	Widget(button),
	Label(button),
	WidgetDecorator(button),
	button_listeners(button.button_listeners) {}

Button::~Button () {}

void Button::draw (void) {
	if (this->is_decorating() ) {
		WidgetDecorator::draw();
	}

	else {
		Label::draw();
	}
}

void Button::add_button_listener (ButtonListener *button_listener) {
	this->button_listeners.push_back(button_listener);
	button_listener->set_listened_button(this);
}

std::vector<ButtonListener*>& Button::get_button_listeners (void) {
	return this->button_listeners;
}

void Button::click (EventHandler *event_handler, SDL_MouseButtonEvent &mouse_button_event) {
	for (int i = 0; (unsigned) i < this->button_listeners.size(); i++) {
		this->button_listeners[i]->on_click_on_button(event_handler, this, mouse_button_event);
	}
}