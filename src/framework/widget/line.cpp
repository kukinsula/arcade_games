#include "line.hpp"

Line::Line (int x, int y, int width, int height) :
	Widget(x, y, width, height) {
}

Line::Line (Position start, Position end) : 
	Widget(start.get_x(), start.get_y(), end.get_x(), end.get_y() ) {
}

void Line::draw () {
	Color background_color = this->get_background_color();
	SDL_Renderer *renderer = this->get_window_renderer();
	Position start = this->get_start();
	Position end = this->get_end();

	SDL_SetRenderDrawColor(renderer, background_color.get_red(), background_color.get_green(), background_color.get_blue(), 255);
	SDL_RenderDrawLine(renderer, start.get_x(), start.get_y(), end.get_x(), end.get_y() );
	SDL_RenderPresent(renderer);
}

Position Line::get_start () const {
	return this->start;
}

Position Line::get_end () const {
	return this->end;
}

void Line::set_start (Position point) {
	this->start = point;
}

void Line::set_end (Position point) {
	this->end = point;
}