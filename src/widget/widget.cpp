#include "../window/window.hpp"
#include "../log/log.hpp"

#include "widget.hpp"

Widget::Widget () :
	window(NULL),
	parent(NULL) {
}

Widget::Widget (int x, int y, int width, int height) :
	position(x, y),
	dimension(width, height),
	window(NULL),
	parent(NULL) {
}

Widget::Widget (Position &position, Dimension &dimension) :
	position(position),
	dimension(dimension),
	window(NULL),
	parent(NULL) {
}

Widget::Widget (const Widget &widget) :
	position(widget.position),
	dimension(widget.dimension),
	window(widget.window),
	background_color(widget.background_color),
	parent(widget.parent),
	drag_and_drop_widget_listeners(widget.drag_and_drop_widget_listeners) {
}

Widget::~Widget () {}

void Widget::add_drag_and_drop_widget_listener (DragAndDropWidgetListener *drag_and_drop_widget_listener) {
	this->drag_and_drop_widget_listeners.push_back(drag_and_drop_widget_listener);
}

void Widget::add_widget (Widget *) {}

bool Widget::is_panel (void) const {
	return false;
}

bool Widget::is_over (int x, int y) const {
	bool result = false;

	if (x >= this->position.get_x() &&
		x <= this->position.get_x() + this->dimension.get_width() &&
		y >= this->position.get_y() &&
		y <= this->position.get_y() + this->dimension.get_height() ) {

		result = true;
	}

	return result;
}

bool Widget::is_over (const Position &position) const {
	return this->is_over(position.get_x(), position.get_y() );
}

void Widget::set_position (Position &position) {
	this->position = position;
}

void Widget::set_dimension (Dimension &dimension) {
	this->dimension = dimension;
}

void Widget::set_window (Window *window) {
	this->window = window;
}

void Widget::set_background_color (Color &color) {
	this->background_color = color;
}

void Widget::set_parent (Widget *parent) {
	this->parent = parent;
}

SDL_Renderer* Widget::get_window_renderer () const {
	if (this->window == NULL) {
		return NULL;
	}

	return this->window->get_renderer();
}

Window* Widget::get_window (void) const {
	return this->window;
}

Position Widget::get_position (void) const {
	return this->position;
}

Dimension Widget::get_dimension (void) const {
	return this->dimension;
}

std::vector<DragAndDropWidgetListener*>& Widget::get_drag_and_drop_widget_listeners (void) {
	return this->drag_and_drop_widget_listeners;
}

Color& Widget::get_background_color (void) {
	return this->background_color;
}

Widget* Widget::get_parent (void) const {
	return this->parent;
}

void Widget::click (EventHandler *, SDL_MouseButtonEvent &) {}

void Widget::over (EventHandler *, SDL_MouseMotionEvent &) {}

void Widget::drag_and_drop (EventHandler *, DragAndDropWidgetEvent, Widget *) {}

std::ostream& operator<<(std::ostream &os, const Widget &widget) {
	os <<
		"position=" << widget.get_position() << ";dimension=" << widget.get_dimension();

	return os;
}