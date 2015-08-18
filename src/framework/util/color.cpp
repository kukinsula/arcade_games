#include "color.hpp"

Color Color::RED = Color(255, 0, 0);
Color Color::GREEN = Color(0, 255, 0);
Color Color::BLUE = Color(0, 0, 255);
Color Color::BLACK = Color(0, 0, 0);
Color Color::WHITE = Color(255, 255, 255);
Color Color::LIGHT_GRAY = Color(200, 200, 200);
Color Color::STRONG_GRAY = Color(100, 100, 100);

Color::Color (int r, int g, int b) :
	r(r),
	g(g),
	b(b) {
}

Color::Color () :
	r(0),
	g(0),
	b(0) {
}

Color::~Color () {
}

int Color::get_red () const {
	return this->r;
}

int Color::get_green () const {
	return this->g;
}

int Color::get_blue () const {
	return this->b;
}