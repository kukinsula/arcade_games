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

		void draw ();
		void clear ();

		void add_widget (Widget *widget);

		Controller* get_controller (void);
		Window* get_window (void);
		std::vector<Widget*> get_widgets () const;

		void set_controller (Controller *controller);
		void set_window (Window *window);
};

#include "controller.hpp"
#include "window.hpp"
#include "../widget/widget.hpp"

#endif