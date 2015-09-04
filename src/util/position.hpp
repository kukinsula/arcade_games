#ifndef POSITION
#define POSITION

#include <string>

class Position {
	private:
		int x, y;

	public:
		Position ();
		Position (const Position &position);
		Position (int x, int y);
		~Position ();

		double distance_to (Position &position) const;

		int get_x (void) const;
		int get_y (void) const;

		void set_x (int x);
		void set_y (int y);
};

std::ostream& operator<<(std::ostream &os, Position &position);

#endif