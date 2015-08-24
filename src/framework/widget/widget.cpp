#include "../window/window.hpp"
#include "../log/log.hpp"

#include "widget.hpp"

Widget::Widget () :
	window(NULL) {
}

Widget::Widget (const Widget &widget) :
	position(widget.position),
	dimension(widget.dimension),
	window(widget.window),
	background_color(widget.background_color) {
}

Widget::Widget (int x, int y, int width, int height) :
	position(x, y),
	dimension(width, height),
	window(NULL) {
}

Widget::Widget (Position position, Dimension dimension) :
	position(position),
	dimension(dimension),
	window(NULL) {
}

Widget::~Widget () {
}

void Widget::add_widget_listener (WidgetListener *widget_listener) {
	this->widget_listeners.push_back(widget_listener);
}

void Widget::add_widget (Widget *widget) {}

bool Widget::is_over (int x, int y) const {
	Position position = this->position;
	Dimension dimension = this->dimension;
	bool result = false;

	if (x >= position.get_x() && x <= position.get_x() + dimension.get_width() && y >= position.get_y() && y <= position.get_y() + dimension.get_height() ) {
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

void Widget::draw () {
	SDL_Rect rect;
	Position position = this->get_position();
	Dimension dimension = this->get_dimension();
	Color background_color = this->get_background_color();
	SDL_Renderer *renderer = NULL;

	MSG(info, "Widget");

	rect.x = position.get_x();
	rect.y = position.get_y();
	rect.w = dimension.get_width();
	rect.h = dimension.get_height();

	renderer = this->get_window_renderer();

	if (renderer != NULL) {
		SDL_SetRenderDrawColor(renderer, background_color.get_red(), background_color.get_green(), background_color.get_blue(), 255);
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);
	}
}

void Widget::set_position (Position point) {
	this->position = point;
}

void Widget::set_dimension (Dimension) {
	this->dimension = dimension;
}

void Widget::set_window (Window *window) {
	this->window = window;
}

void Widget::set_background_color (Color color) {
	this->background_color = color;
}

SDL_Renderer* Widget::get_window_renderer () const {
	return this->window->get_renderer();
}

Window* Widget::get_window () const {
	return this->window;
}

Position Widget::get_position () const {
	return this->position;
}

Dimension Widget::get_dimension () const {
	return this->dimension;
}

std::vector<WidgetListener*> Widget::get_widget_listeners () const {
	return this->widget_listeners;
}

Color Widget::get_background_color () {
	return this->background_color;
}