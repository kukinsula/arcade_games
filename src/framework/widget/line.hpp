#ifndef LINE
#define LINE

#include "../util/position.hpp"

#include "widget.hpp"

class Line : public Widget {
	private:
		Position start, end;

	public:
		Line (Position start, Position end);
		Line (int x, int y, int width, int height);

		void draw ();

		void set_start (Position point);
		void set_end (Position point);

		Position get_start () const;
		Position get_end () const;
};

#endif