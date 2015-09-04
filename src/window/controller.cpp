#include "controller.hpp"

Controller::Controller () :
	view(NULL) 	{
}

Controller::Controller (const Controller &controller) :
	view(controller.view) {
}

Controller::~Controller () {}

View* Controller::get_view (void) const {
	return this->view;
}

void Controller::set_view (View *view) {
	this->view = view;
}