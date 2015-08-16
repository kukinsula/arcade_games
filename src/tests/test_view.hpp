#ifndef TEST_VIEW
#define TEST_VIEW

#include "../framework/window/view.hpp"
#include "../framework/widget/rectangle.hpp"

class TestView : public View {
	private:
		Rectangle *rectangle;

	public:
		TestView ();

		Rectangle* get_rectangle () const;

		// void draw ();
};

#endif