#include "dimension.hpp"

Dimension::Dimension () : 
	width(0),
	height(0) {
}

Dimension::Dimension (int width, int height) : 
	width(width),
	height(height) {
}

int Dimension::get_width (void) const {
	return this->width;
}

int Dimension::get_height (void) const {
	return this->height;
}

void Dimension::set_width (int width) {
	this->width = width;
}

void Dimension::set_height (int height) {
	this->height = height;
}