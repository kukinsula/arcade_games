#ifndef PANEL
#define PANEL

#include <vector>

#include "widget.hpp"

class Panel : public Widget {
	private:
		std::vector<Widget*> widgets;

	public:
		Panel (void);
		Panel (const Panel &panel);
		Panel (int x, int y, int width, int height);
		Panel (Position position, Dimension dimension);
		~Panel ();

		bool is_panel (void) const;
		void add_widget (Widget *widget);

		void draw ();
};

#endif