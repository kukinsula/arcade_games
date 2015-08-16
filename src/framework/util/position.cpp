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

double Position::distance_to (Position point) const {
	return sqrt(pow(point.get_x() - this->get_x(), 2) + pow(point.get_y() - this->get_y(), 2) );
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

std::ostream& operator<<(std::ostream &os, Position position) {
	std::stringstream sstm;

	sstm <<
		"(" <<
		position.get_x() << ", " <<
		position.get_y() << ")";

	os << sstm.str();

	return os;
}