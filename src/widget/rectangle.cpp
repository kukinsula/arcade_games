#include "SDL.h"
#include <SDL2/SDL_image.h>

#include "rectangle.hpp"

#include "../log/log.hpp"

Rectangle::Rectangle () : Widget () {}

Rectangle::Rectangle (int x, int y, int width, int height) :
	Widget(x, y, width, height) {}

Rectangle::Rectangle (Position &position, Dimension &dimension) :
	Widget(position, dimension) {}

Rectangle::Rectangle (const Rectangle &rectangle) :
	Widget(rectangle) {}

Rectangle::~Rectangle () {}

void Rectangle::draw_background (void) {
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

void Rectangle::draw (void) {
	this->draw_background();
}

std::ostream& operator<<(std::ostream &os, const Rectangle &rectangle) {
	const Widget &widget = rectangle;

	os << "[" << widget << "]";

	return os;
}