#ifndef LINE
#define LINE

#include "../util/position.hpp"

#include "widget.hpp"

class Line : public Widget {
	private:
		Position start, end;

	public:
		Line (Position &start, Position &end);
		Line (int x, int y, int width, int height);
		Line (const Line &line);

		void draw (void);

		void set_start (Position &position);
		void set_end (Position &position);

		Position& get_start (void);
		Position& get_end (void);
};

#endif