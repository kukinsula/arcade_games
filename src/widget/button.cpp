#include "button.hpp"

Button::Button (std::string text) :
	Label(text) {}

Button::Button (int x, int y, int width, int height, std::string text) :
	Label(x, y, width, height, text) {}

Button::Button (Position position, Dimension dimension, std::string text) :
	Label(position, dimension, text) {}

Button::Button (const Button &button) :
	Label(button),
	button_listeners(button.button_listeners) {}

Button::~Button () {}

void Button::draw (void) {
	Label::draw();
}

void Button::add_button_listener (ButtonListener *clic_on_widget_listener) {
	this->button_listeners.push_back(clic_on_widget_listener);
}

std::vector<ButtonListener*>& Button::get_button_listeners (void) {
	return this->button_listeners;
}

void Button::click (EventHandler *event_handler, SDL_MouseButtonEvent &mouse_button_event) {
	for (int i = 0; (unsigned) i < this->button_listeners.size(); i++) {
		this->button_listeners[i]->set_listened_button(this);
		this->button_listeners[i]->on_click_on_button(event_handler, this, mouse_button_event);
	}
}