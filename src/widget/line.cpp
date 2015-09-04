#include "line.hpp"

Line::Line (int x, int y, int width, int height) :
	Widget(x, y, width, height) {
}

Line::Line (Position &start, Position &end) : 
	Widget(start.get_x(), start.get_y(), end.get_x(), end.get_y() ) {
}

Line::Line (const Line &line) :
	Widget(line),
	start(line.start),
	end(line.end) {
}

void Line::draw (void) {
	Color background_color = this->get_background_color();
	SDL_Renderer *renderer = this->get_window_renderer();
	Position start = this->get_start();
	Position end = this->get_end();

	SDL_SetRenderDrawColor(
		renderer,
		background_color.get_red(),
		background_color.get_green(),
		background_color.get_blue(),
		background_color.get_alpha() );

	SDL_RenderDrawLine(renderer, start.get_x(), start.get_y(), end.get_x(), end.get_y() );
	SDL_RenderPresent(renderer);
}

Position& Line::get_start (void) {
	return this->start;
}

Position& Line::get_end (void) {
	return this->end;
}

void Line::set_start (Position &position) {
	this->start = position;
}

void Line::set_end (Position &position) {
	this->end = position;
}