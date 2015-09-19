#include "big_controller.hpp"

BigController::BigController () {}

BigController::BigController (const BigController &big_controller) :
	Controller(big_controller),
	DragAndDropListener(),
	DropFileListener(),
	GameControllerListener(),
	KeyboardListener(),
	MouseListener(),
	QuitListener(),
	MouseOverWidgetListener(),
	ClickOnWidgetListener(),
	DragAndDropWidgetListener(),
	WindowListener() {
}

BigController::~BigController () {}

void BigController::on_drop_file (EventHandler *, SDL_DropEvent) {}

void BigController::on_quit (EventHandler *) {}