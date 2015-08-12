#include "SDL.h"
#include <SDL2/SDL_image.h>

#include "rectangle.hpp"

#include "../log/log.hpp"

Rectangle::Rectangle (int x, int y, int width, int height) :
	Widget (x, y, width, height)
	{
}

void Rectangle::draw () {
	SDL_Rect rect;
	SDL_Surface *surface = NULL;
	SDL_Texture *texture = NULL;
	SDL_Renderer *renderer = this->get_window_renderer();

	rect.x = this->get_x();
	rect.y = this->get_y();
	rect.w = this->get_width();
	rect.h = this->get_height();

	surface = SDL_CreateRGBSurface(0, this->get_width(), this->get_height(), 32, 0 , 0, 0, 0);

	if (surface == NULL) {
		MSG(error, "Can't create SDL_Surface':");
		MSG(error, SDL_GetError() );
		return ;
	}

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	if (texture == NULL) {
		MSG(error, "Can't create SDL_Texture':");
		MSG(error, SDL_GetError() );
		return ;
	}

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	// SDL_RenderFillRect(renderer, &rect);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, &rect, &rect);
	SDL_RenderPresent(renderer);
}