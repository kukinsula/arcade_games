#ifndef DRAG_AND_DROP_CONTROLLER_TEST
#define DRAG_AND_DROP_CONTROLLER_TEST

#include "../framework/window/controller.hpp"
#include "../framework/event/drag_and_drop_listener.hpp"

class DragAndDropControllerTest :
	public Controller,
	public DragAndDropListener {

	public:
		void on_drag (EventHandler *handler);
		void on_dragging (EventHandler *handler);
		void on_drop (EventHandler *handler);
};

#endif