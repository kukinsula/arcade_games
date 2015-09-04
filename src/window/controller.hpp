#ifndef CONTROLLER
#define CONTROLLER

class View;

class Controller {
	private:
		View *view;

	public:
		Controller ();
		Controller (const Controller &controller);
		~Controller ();

		View* get_view (void) const;

		void set_view (View *view);
};

#include "view.hpp"

#endif