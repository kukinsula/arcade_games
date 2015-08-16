#ifndef RECTANGLE
#define RECTANGLE

#include "../window/window.hpp"

class Rectangle : public Widget {
	public:
		Rectangle ();
		Rectangle (int x = 0, int y = 0, int width = 0, int height = 0);
		~Rectangle ();

		void draw ();
};

#endif