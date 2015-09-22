#include "../log/log.hpp"

#include "label.hpp"

Label::Label (std::string text) :
	Widget(),
	text(text) {}

Label::Label (int x, int y, int width, int height, std::string text) :
	Widget(x, y, width, height),
	text(text) {}

Label::Label (Position position, Dimension dimension, std::string text) :
	Widget(position, dimension),
	text(text) {}

Label::Label (const Label &label) :
	Widget(label),
	text(label.text) {}

Label::~Label () {
	TTF_CloseFont(this->font);
}

void Label::draw (void) {
	SDL_Renderer *renderer = NULL;
	SDL_Surface *surface = NULL;
	SDL_Texture *texture = NULL;
	SDL_Color color = {0, 0, 0, 255};
	SDL_Rect rect;

	rect.x = this->get_position().get_x();
	rect.y = this->get_position().get_y();
	rect.w = this->get_dimension().get_width();
	rect.h = this->get_dimension().get_height();

	renderer = this->get_window()->get_renderer();

	this->font = TTF_OpenFont("assets/fonts/angelina.ttf", 10);
	TTF_SetFontStyle(this->font, TTF_STYLE_NORMAL);

	if (this->font == NULL) {
		printf("font is NULL, SDL_GetError = %s, TTF_GetError = %s\n", SDL_GetError(), TTF_GetError() );
		return ;
	}

	surface = TTF_RenderText_Blended(this->font, this->get_text().c_str(), color);

	if (surface == NULL) {
		MSG(error, "surface is NULL");
		return ;
	}

	texture = SDL_CreateTextureFromSurface(renderer, surface);

	if (texture == NULL) {
		MSG(error, "texture is NULL");
		return ;
	}

	Widget::draw_background();
	SDL_RenderCopy(renderer, texture, NULL, &rect);
	SDL_RenderPresent(renderer);

	SDL_FreeSurface(surface);
}

void Label::set_text (std::string &text) {
	this->text = text;
}

std::string Label::get_text (void) const {
	return this->text;
}