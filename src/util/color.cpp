#include "color.hpp"

Color Color::RED = Color(255, 0, 0);
Color Color::GREEN = Color(0, 255, 0);
Color Color::BLUE = Color(0, 0, 255);
Color Color::BLACK = Color(0, 0, 0);
Color Color::WHITE = Color(255, 255, 255);
Color Color::LIGHT_GRAY = Color(200, 200, 200);
Color Color::STRONG_GRAY = Color(100, 100, 100);

Color::Color (int red, int green, int blue, int alpha) :
	red(red),
	green(green),
	blue(blue),
	alpha(alpha) {
}

Color::Color () :
	red(0),
	green(0),
	blue(0),
	alpha(255) {
}

Color::Color (const Color &color) :
	red(color.red),
	green(color.green),
	blue(color.blue),
	alpha(color.alpha) {
}


Color::~Color () {
}

void Color::set_red (int red) {
	this->red = red;
}

void Color::set_green (int green) {
	this->green = green;
}

void Color::set_blue (int blue) {
	this->blue = blue;
}

void Color::set_alpha (int alpha) {
	this->alpha = alpha;
}

int Color::get_red (void) const {
	return this->red;
}

int Color::get_green (void) const {
	return this->green;
}

int Color::get_blue (void) const {
	return this->blue;
}

int Color::get_alpha (void) const {
	return this->alpha;
}