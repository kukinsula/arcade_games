#include "big_controller.hpp"

BigController::BigController () {}

BigController::BigController (const BigController &big_controller) :
	Controller(big_controller),
	DragAndDropListener(big_controller),
	DropFileListener(big_controller),
	GameControllerListener(big_controller),
	KeyboardListener(big_controller),
	MouseListener(big_controller),
	QuitListener(big_controller),
	WidgetListener(big_controller),
	WindowListener(big_controller) {
}

BigController::~BigController () {}

void BigController::on_drop_file (EventHandler *, SDL_DropEvent) {}

void BigController::on_quit (EventHandler *) {}