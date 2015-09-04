#include "panel.hpp"

#include "../log/log.hpp"

Panel::Panel (void) {}

Panel::Panel (const Panel &panel) :
	Widget(panel),
	widgets(panel.widgets) {
}

Panel::Panel (int x, int y, int width, int height) :
	Widget(x, y, width, height) {
}

Panel::Panel (Position &position, Dimension &dimension) :
	Widget(position, dimension) {
}

Panel::~Panel () {}

bool Panel::is_panel (void) const {
	return true;
}

void Panel::add_widget (Widget *widget) {
	this->widgets.push_back(widget);
}

void Panel::draw (void) {
	Widget::draw();
	MSG(info, "PANEL");

	// for (unsigned int i = 0; i < this->widgets.size(); i++) {
	// 	this->widgets[i]->draw();
	// }
}