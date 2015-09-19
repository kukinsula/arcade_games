#include <sstream>

#include "mouse_wheel_direction.hpp"
#include "../log/log.hpp"

#include "mouse.hpp"

Mouse::Mouse () {
	memset(this->buttons, 0, sizeof(this->buttons) );
}

Mouse::Mouse (const Mouse &mouse) :
	position(mouse.position),
	relative_position(mouse.relative_position),
	wheel_position(mouse.wheel_position) {}

Mouse::~Mouse () {}

bool Mouse::is_button_pressed (Uint8 button) const {
	return this->buttons[button] == 1;
}

void Mouse::update (SDL_MouseMotionEvent &mouse_motion_event) {
	Position position(mouse_motion_event.x, mouse_motion_event.y);
	Position relative_position(mouse_motion_event.xrel, mouse_motion_event.yrel);

	this->position = position;
	this->relative_position = relative_position;
}

void Mouse::update (SDL_MouseButtonEvent &mouse_button_event) {
	this->buttons[mouse_button_event.button] = !this->buttons[mouse_button_event.button];
}

void Mouse::update (SDL_MouseWheelEvent &mouse_wheel_event) {
	MouseWheelDirection direction = get_mouse_wheel_direction(mouse_wheel_event);

	switch (direction) {
		case MOUSE_WHEEL_UP:
			this->wheel_position.set_y(this->wheel_position.get_y() + 1);
			break;

		case MOUSE_WHEEL_DOWN:
			this->wheel_position.set_y(this->wheel_position.get_y() - 1);
			break;

		case MOUSE_WHEEL_LEFT:
			this->wheel_position.set_x(this->wheel_position.get_x() - 1);
			break;

		case MOUSE_WHEEL_RIGHT:
			this->wheel_position.set_x(this->wheel_position.get_x() + 1);
			break;

		default:
			break;
	}
}

void Mouse::set_position (Position &position) {
	this->position = position;
}

void Mouse::set_relative_position (Position &position) {
	this->relative_position = position;
}

Position Mouse::get_position (void) const {
	return this->position;
}

Position Mouse::get_relative_position (void) const {
	return this->relative_position;
}

const char* Mouse::get_buttons (void) const {
	return this->buttons;
}

Position Mouse::get_wheel_position (void) const {
	return this->wheel_position;
}

std::ostream& operator<< (std::ostream &os, const Mouse &mouse) {
	Position position = mouse.get_position();
	Position relative_position = mouse.get_relative_position();

	os
		<< "position=" << position
		<< ";relative=" << relative_position
		<< ";buttons[L]=" << mouse.is_button_pressed(SDL_BUTTON_LEFT)
		<< ";buttons[M]=" << mouse.is_button_pressed(SDL_BUTTON_MIDDLE)
		<< ";buttons[R]=" << mouse.is_button_pressed(SDL_BUTTON_RIGHT)
		<< ";buttons[X1]=" << mouse.is_button_pressed(SDL_BUTTON_X1)
		<< ";buttons[X2]=" << mouse.is_button_pressed(SDL_BUTTON_X2)
		<< ";wheel=" << mouse.get_wheel_position();

	return os;
}