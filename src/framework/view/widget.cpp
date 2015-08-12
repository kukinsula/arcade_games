#include "../window/window.hpp"

#include "widget.hpp"

Widget::Widget (int x, int y, int width, int height) :
	x(x),
	y(y),
	width(width),
	height(height),
	window(NULL)
	{
}

void Widget::add_action_listener (ActionListener * action_listener) {
	this->action_listeners.push_back(action_listener);
}

bool Widget::is_over (int x, int y) const {
	bool result = false;

	if (x >= this->x && x <= this->x + this->width && y >= this->y && y <= this->y + this->height) {
		result = true;
	}

	return result;
}

void Widget::set_window (Window *window) {
	this->window = window;
}

Window* Widget::get_window () const {
	return this->window;
}

SDL_Renderer* Widget::get_window_renderer () const {
	return this->window->get_renderer();
}

int Widget::get_x () const {
	return this->x;
}

int Widget::get_y () const {
	return this->y;
}

int Widget::get_width () const {
	return this->width;
}

int Widget::get_height () const {
	return this->height;
}

std::vector<ActionListener*> Widget::get_action_listeners () const {
	return this->action_listeners;
}