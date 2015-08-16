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


int main (void) {
	init();

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