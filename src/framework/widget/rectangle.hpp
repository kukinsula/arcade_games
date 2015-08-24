#ifndef RECTANGLE
#define RECTANGLE

#include "../window/window.hpp"

class Rectangle : public Widget {
	public:
		Rectangle ();
		Rectangle (int x, int y, int width, int height);
		Rectangle (Position position, Dimension dimension);
		~Rectangle ();

		void draw ();
};

#endif