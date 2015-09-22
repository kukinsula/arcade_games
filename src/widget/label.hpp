#ifndef __LABEL__
#define __LABEL__

#include <string>

#include "SDL.h"
#include "SDL_ttf.h"

#include "widget.hpp"

class Label : public Widget {
	private:
		std::string text;
		TTF_Font *font;
		// Color;
		int font_size;

	public:
		Label (std::string text);
		Label (int x, int y, int width, int height, std::string text);
		Label (Position position, Dimension dimension, std::string text);
		Label (const Label &label);
		~Label ();

		void draw (void);

		void set_text (std::string &text);

		std::string get_text (void) const;
};

#endif