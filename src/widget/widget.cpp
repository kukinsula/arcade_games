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

void Widget::add_mouse_over_widget_listener (MouseOverWidgetListener *mouse_over_widget_listener) {
	this->mouse_over_widget_listeners.push_back(mouse_over_widget_listener);
}

void Widget::add_drag_and_drop_widget_listener (DragAndDropWidgetListener *drag_and_drop_widget_listener) {
	this->drag_and_drop_widget_listeners.push_back(drag_and_drop_widget_listener);
}

void Widget::add_widget (Widget *) {}

bool Widget::is_over (int x, int y) const {
	Position position = this->position;
	Dimension dimension = this->dimension;
	bool result = false;

	if (x >= position.get_x() &&
		x <= position.get_x() + dimension.get_width() &&
		y >= position.get_y() &&
		y <= position.get_y() + dimension.get_height() ) {

		result = true;
	}

	return result;
}

bool Widget::is_over (const Position &position) const {
	return this->is_over(position.get_x(), position.get_y() );
}

bool Widget::is_panel (void) const {
	return false;
}

void Widget::draw_background (void) {
	Color background_color = this->get_background_color();
	Dimension dimension = this->get_dimension();
	Position position = this->get_position();
	SDL_Renderer *renderer = NULL;
	SDL_Rect rect;

	rect.x = position.get_x();
	rect.y = position.get_y();
	rect.w = dimension.get_width();
	rect.h = dimension.get_height();

	renderer = this->get_window_renderer();

	if (renderer != NULL) {
		SDL_SetRenderDrawColor(
			renderer,
			background_color.get_red(),
			background_color.get_green(),
			background_color.get_blue(),
			background_color.get_alpha() );

		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);
	}
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
	return this->window->get_renderer();
}

Window* Widget::get_window (void) const {
	return this->window;
}

Position& Widget::get_position (void) {
	return this->position;
}

Dimension& Widget::get_dimension (void) {
	return this->dimension;
}

std::vector<MouseOverWidgetListener*>& Widget::get_mouse_over_widget_listeners (void) {
	return this->mouse_over_widget_listeners;
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