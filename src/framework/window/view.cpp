#include "view.hpp"

View::View () :
	window(NULL),
	controller(NULL) {
}

View::View (const View &view) :
	window(view.window),
	controller(view.controller),
	widgets(view.widgets) {
}

View::~View () {
}

void View::draw () {
	this->clear();

	for (unsigned int i = 0; i < this->widgets.size(); i++) {
		this->widgets[i]->draw();
	}
}

void View::clear () {
	SDL_Renderer *renderer = this->window->get_renderer();

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void View::add_widget (Widget *widget) {
	widget->set_window(this->window);
	this->widgets.push_back(widget);
}

Controller* View::get_controller (void) {
	return this->controller;
}

Window* View::get_window () {
	return this->window;
}

std::vector<Widget*> View::get_widgets () const {
	return this->widgets;
}

void View::set_controller (Controller *controller) {
	this->controller = controller;
}

void View::set_window (Window *window) {
	this->window = window;

	for (unsigned int i = 0; i < this->widgets.size(); i++) {
		this->widgets[i]->set_window(window);
	}
}