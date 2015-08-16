#ifndef POSITION
#define POSITION

#include <string>

class Position {
	private:
		int x, y;

	public:
		Position (void);
		Position (int x, int y);

		double distance_to (Position point) const;

		int get_x (void) const;
		int get_y (void) const;

		void set_x (int x);
		void set_y (int x);
};

std::ostream& operator<<(std::ostream &os, Position point);

#endif