#include <sstream>
#include <math.h>

#include "position.hpp"

Position::Position (void) :
	x(0),
	y(0) {
}

Position::Position (int x, int y) :
	x(x),
	y(y) {
}

Position::Position (const Position &position) :
	x(position.x),
	y(position.y) {
}

Position::~Position () {}

double Position::distance_to (Position &position) const {
	return sqrt(pow(position.get_x() - this->get_x(), 2) + pow(position.get_y() - this->get_y(), 2) );
}

int Position::get_x (void) const {
	return this->x;
}

int Position::get_y (void) const {
	return this->y;
}

void Position::set_x (int x) {
	this->x = x;
}

void Position::set_y (int y) {
	this->y = y;
}

std::ostream& operator<<(std::ostream &os, const Position &position) {
	os << "[x=" << position.get_x() << ";y=" << position.get_y() << "]";

	return os;
}