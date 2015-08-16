#include "drop_file_controller_test.hpp"

#include "../framework/log/log.hpp"

void DropFileControllerTest::on_drop_file (EventHandler *, SDL_DropEvent drop_event) {
	std::string str = "TestController::on_drop_file '" + std::string(drop_event.file) +"'";

	MSG(info, str);
}