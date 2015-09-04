#include <stdio.h>
#include "SDL.h"

#include "main.hpp"

#include "window/window.hpp"
#include "window/view.hpp"
#include "event/event_handler.hpp"
#include "log/log.hpp"
#include "log/console_logger.hpp"
#include "log/file_logger.hpp"
#include "log/xml_logger.hpp"
#include "widget/rectangle.hpp"
#include "widget/line.hpp"


int main (void) {
	Window window("TEST", Dimension(400, 400) );
	View view;

	init();

	window.set_view(&view);

	window.open();
	window.close();

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

void uninit (void) {
	MSG(info, "closing Arcade Games");

	Log::quit();
	SDL_Quit();
}