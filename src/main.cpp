#include <stdio.h>
#include "SDL.h"

#include "main.hpp"

#include "framework/window/window.hpp"
#include "framework/window/view.hpp"
#include "framework/event/event_handler.hpp"
#include "framework/log/log.hpp"
#include "framework/log/console_logger.hpp"
#include "framework/log/file_logger.hpp"
#include "framework/log/xml_logger.hpp"
#include "framework/widget/rectangle.hpp"
#include "framework/widget/line.hpp"

#include "tests/test_controller.hpp"
#include "tests/keyboard_controller_test.hpp"
#include "tests/mouse_controller_test.hpp"
#include "tests/window_controller_test.hpp"
#include "tests/widget_controller_test.hpp"
#include "tests/drop_file_controller_test.hpp"
#include "tests/drag_and_drop_controller_test.hpp"
#include "tests/game_controller_test.hpp"
#include "tests/test_view.hpp"


int main (void) {
	init();

	keyboard_controller_test();

	uninit();

	return 0;
}

void init (void) {
	ConsoleLogger *console_logger = new ConsoleLogger(critical);
	FileLogger *file_logger = new FileLogger("log.txt", critical);
	XMLLogger *xml_logger = new XMLLogger("log.xml", critical);

	Log::add_logger(console_logger);
	Log::add_logger(file_logger);
	Log::add_logger(xml_logger);

	MSG(info, "starting Arcade Games");

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER);
	SDL_GameControllerEventState(SDL_ENABLE);
}

void keyboard_controller_test (void) {
	Window window("Test keyboard controller");
	EventHandler *event_handler = window.get_event_handler();	
	KeyboardControllerTest controller;
	Rectangle rectangle(0, 0, 40, 40);
	View view;

	view.add_widget(&rectangle);
	view.set_controller(&controller);

	controller.set_view(&view);

	event_handler->add_keyboard_listener(&controller);

	window.set_view(&view);
	window.set_event_handler(event_handler);

	window.open();
	window.close();
}

void mouse_controller_test (void) {
	Window window("Test mouse controller");
	EventHandler *event_handler = window.get_event_handler();	
	MouseControllerTest controller;
	View view;

	view.set_controller(&controller);
	controller.set_view(&view);

	event_handler->add_mouse_listener(&controller);
	event_handler->add_keyboard_listener(&controller);

	window.set_view(&view);
	window.set_event_handler(event_handler);

	window.open();
	window.close();
}

void window_controller_test (void) {
	Window window("Test window controller");
	EventHandler *event_handler = window.get_event_handler();	
	WindowControllerTest controller;
	View view;

	view.set_controller(&controller);
	controller.set_view(&view);

	event_handler->add_window_listener(&controller);

	window.set_view(&view);
	window.set_event_handler(event_handler);

	window.open();
	window.close();
}

void widget_controller_test (void) {
	Window window("Test window controller");
	EventHandler *event_handler = window.get_event_handler();	
	WidgetControllerTest controller;
	Rectangle rectangle(0, 0, 40, 40);
	Rectangle rectangle2(300, 300, 40, 40);
	View view;

	rectangle2.set_background_color(Color::RED);

	view.add_widget(&rectangle);
	view.add_widget(&rectangle2);
	view.set_controller(&controller);

	rectangle.add_widget_listener(&controller);
	rectangle2.add_widget_listener(&controller);
	controller.set_view(&view);

	window.set_view(&view);
	window.set_event_handler(event_handler);

	window.open();
	window.close();
}

void drop_file_controller_test (void) {
	Window window("Test drop file controller");
	EventHandler *event_handler = window.get_event_handler();	
	DropFileControllerTest controller;
	View view;

	view.set_controller(&controller);
	controller.set_view(&view);

	event_handler->add_drop_file_listener(&controller);

	window.set_view(&view);
	window.set_event_handler(event_handler);

	window.open();
	window.close();
}

void drag_and_drop_controller_test (void) {
	Window window("Test drag and drop controller");
	EventHandler *event_handler = window.get_event_handler();	
	DragAndDropControllerTest controller;
	View view;

	view.set_controller(&controller);
	controller.set_view(&view);

	event_handler->add_drag_and_drop_listener(&controller);

	window.set_view(&view);
	window.set_event_handler(event_handler);

	window.open();
	window.close();
}

void game_controller_test (void) {
	Window window("Test drag and drop controller");
	EventHandler *event_handler = window.get_event_handler();	
	GameControllerTest controller;
	View view;

	view.set_controller(&controller);
	controller.set_view(&view);

	event_handler->add_game_controller_listener(&controller);

	window.set_view(&view);
	window.set_event_handler(event_handler);

	window.open();
	window.close();
}

void uninit (void) {
	MSG(info, "closing Arcade Games");

	Log::quit();
	SDL_Quit();
}