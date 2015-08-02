#include "SDL.h"

#include "game_controller_listener.hpp"

void GameControllerListener::on_controller_device_added (EventHandler *, SDL_ControllerDeviceEvent) {
}

void GameControllerListener::on_controller_device_removed (EventHandler *, SDL_ControllerDeviceEvent) {
}

void GameControllerListener::on_controller_device_remapped (EventHandler *, SDL_ControllerDeviceEvent) {
}

void GameControllerListener::on_game_controller_button_press (EventHandler *, SDL_ControllerButtonEvent) {
}

void GameControllerListener::on_game_controller_button_unpress (EventHandler *, SDL_ControllerButtonEvent) {
}

void GameControllerListener::on_game_controller_axis_motion (EventHandler *, SDL_ControllerAxisEvent) {
}