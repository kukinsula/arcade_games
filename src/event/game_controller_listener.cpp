#include "SDL.h"

#include "game_controller_listener.hpp"

void GameControllerListener::on_controller_device_added (EventInput *, SDL_ControllerDeviceEvent) {
}

void GameControllerListener::on_controller_device_removed (EventInput *, SDL_ControllerDeviceEvent) {
}

void GameControllerListener::on_controller_device_remapped (EventInput *, SDL_ControllerDeviceEvent) {
}

void GameControllerListener::on_game_controller_button_press (EventInput *, SDL_ControllerButtonEvent) {
}

void GameControllerListener::on_game_controller_button_unpress (EventInput *, SDL_ControllerButtonEvent) {
}

void GameControllerListener::on_game_controller_axis_motion (EventInput *, SDL_ControllerAxisEvent) {
}