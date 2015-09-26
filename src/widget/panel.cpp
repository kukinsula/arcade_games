#include "panel.hpp"

#include "../log/log.hpp"

Panel::Panel () {}

Panel::Panel (const Panel &panel) :
	Widget(panel),
	Rectangle(panel),
	widgets(panel.widgets) {
}

Panel::Panel (int x, int y, int width, int height) :
	Rectangle(x, y, width, height) {
}

Panel::Panel (Position &position, Dimension &dimension) :
	Rectangle(position, dimension) {
}

Panel::~Panel () {}

bool Panel::is_panel (void) const {
	return true;
}

void Panel::add_widget (Widget *widget) {
	widget->set_parent(this);
	widget->set_window(this->get_window() );

	this->widgets.push_back(widget);
}

void Panel::draw (void) {
	this->draw_background();

	for (unsigned int i = 0; i < this->widgets.size(); i++) {
		this->widgets[i]->draw();
	}
}