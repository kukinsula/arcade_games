#ifndef VIEW
#define VIEW

#include <vector>

class Controller;
class Window;
class Widget;

class View {
	private:
		Window *window;
		Controller *controller;

		std::vector<Widget*> widgets;

	public:
		View ();
		View (const View &view);
		~View ();

		void draw (void);
		void clear (void);

		void add_widget (Widget *widget);

		Controller* get_controller (void) const;
		Window* get_window (void) const;
		std::vector<Widget*>& get_widgets (void);

		void set_controller (Controller *controller);
		void set_window (Window *window);
};

#include "controller.hpp"
#include "window.hpp"
#include "../widget/widget.hpp"

#endif