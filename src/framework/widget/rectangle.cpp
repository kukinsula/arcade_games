#include "SDL.h"
#include <SDL2/SDL_image.h>

#include "rectangle.hpp"

#include "../log/log.hpp"

Rectangle::Rectangle () : Widget () {
}

Rectangle::Rectangle (int x, int y, int width, int height) : Widget (x, y, width, height) {
}

Rectangle::~Rectangle () {
}

void Rectangle::draw () {
	SDL_Rect rect;
	Position position = this->get_position();
	Dimension dimension = this->get_dimension();
	Color background_color = this->get_background_color();
	SDL_Renderer *renderer = NULL;

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