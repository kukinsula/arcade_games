#include "../framework/log/log.hpp"

#include "test_view.hpp"

TestView::TestView () {
	this->rectangle = new Rectangle(0, 0, 20, 20);
	this->rectangle->set_background_color(Color::RED);

	this->add_widget(this->rectangle);
}

Rectangle* TestView::get_rectangle () const {
	return this->rectangle;
}

// void TestView::draw () {
// 	View::draw();

// 	// this->rectangle->draw();

// 	MSG(info, "ICI");
// }