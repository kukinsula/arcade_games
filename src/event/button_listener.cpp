#include "button_listener.hpp"

ButtonListener::ButtonListener () : listened_button(NULL) {}

ButtonListener::ButtonListener (const ButtonListener &button_listener) :
	listened_button(button_listener.listened_button) {}

ButtonListener::~ButtonListener () {}

void ButtonListener::set_listened_button (Button *button) {
	this->listened_button = button;
}

Button* ButtonListener::get_listened_button (void) {
	return this->listened_button;
}