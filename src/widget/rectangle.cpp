#include "SDL.h"
#include <SDL2/SDL_image.h>

#include "rectangle.hpp"

#include "../log/log.hpp"

Rectangle::Rectangle () : Widget () {
}

Rectangle::Rectangle (int x, int y, int width, int height) :
	Widget (x, y, width, height) {
}

Rectangle::Rectangle (Position &position, Dimension &dimension) :
	Widget (position, dimension) {
}

Rectangle::Rectangle (const Rectangle &rectangle) :
	Widget(rectangle) {
}

Rectangle::~Rectangle () {
}

void Rectangle::draw (void) {
	Widget::draw_background();
}