#ifndef GAME_CONTROLLER_LISTENER
#define GAME_CONTROLLER_LISTENER

/**
 * @file game_controller_listener.hpp
 * @version 0.1
 */

class EventHandler;

/**
 * @class GameControllerListener
 * @brief Listens to game controller related events.
 * @see EventHandler
 *
 * GameControllerListener can listen to events related to game controllers.
 * Subclasses should register to an EventHandler and override one of the
 * virtual methods below to be notified of game controllers events.
 */
class GameControllerListener {
	private:
		static const char *game_controller_mapping_file_name;
		SDL_GameController *game_controller;
		int number_of_joysticks;

	public:
		/**
		 * @brief Constructor
		 *
		 * Constructs a GameControllerListener.
		 */
		GameControllerListener ();

		/**
		 * @brief Copy constructor
		 *
		 * Constructs a GameControllerListener from another GameControllerListener.
		 */
		GameControllerListener (const GameControllerListener &game_controller_listener);

		/**
		 * @brief Destructor
		 *
		 * Destructs a GameControllerListener.
		 */
		~GameControllerListener ();

		/**
		 * @brief method called whenever a game condroller device is added
		 * @param event_handler: the EventHandler to which the GameControllerListener is registered to
		 * @param controller_device_event: the SDL_ControllerDeviceEvent triggered
		 *
		 * GameControllerListeners can be notified when a game controller is
		 * added by overriding this method. GameControllerListeners need to
		 * register to an EventHandler to receive these events.
		 */
		virtual void on_controller_device_added (EventHandler *event_handler, SDL_ControllerDeviceEvent controller_device_event);

		/**
		 * @brief method called whenever a game condroller device is removed
		 * @param event_handler: the EventHandler to which the GameControllerListener is registered to
		 * @param controller_device_event: the SDL_ControllerDeviceEvent triggered
		 *
		 * GameControllerListeners can be notified when a game controller is
		 * removed by overriding this method. GameControllerListeners need to
		 * register to an EventHandler to receive these events.
		 */
		virtual void on_controller_device_removed (EventHandler *event_handler, SDL_ControllerDeviceEvent controller_device_event);
		
		/**
		 * @brief method called whenever a game condroller device is remapped
		 * @param event_handler: the EventHandler to which the GameControllerListener is registered to
		 * @param controller_device_event: the SDL_ControllerDeviceEvent triggered
		 *
		 * GameControllerListeners can be notified when a game controller is
		 * remapped by overriding this method. GameControllerListeners need to
		 * register toan EventHandler to receive these events.
		 */
		virtual void on_controller_device_remapped (EventHandler *event_handler, SDL_ControllerDeviceEvent controller_device_event);

		/**
		 * @brief method called whenever a button is pressed on a game condroller
		 * @param event_handler: the EventHandler to which the GameControllerListener is registered to
		 * @param controller_button_event: the SDL_ControllerButtonEvent triggered
		 *
		 * GameControllerListeners can be notified when a game controller button is
		 * pressed by overriding this method. GameControllerListeners need to
		 * register to an EventHandler to receive these events.
		 */
		virtual void on_game_controller_button_press (EventHandler *event_handler, SDL_ControllerButtonEvent controller_button_event);

		/**
		 * @brief method called whenever a button is unpressed on a game condroller
		 * @param event_handler: the EventHandler to which the GameControllerListener is registered to
		 * @param controller_button_event: the SDL_ControllerButtonEvent triggered
		 *
		 * GameControllerListeners can be notified when a game controller button is
		 * unpressed by overriding this method. GameControllerListeners need to
		 * register to an EventHandler to receive these events.
		 */
		virtual void on_game_controller_button_unpress (EventHandler *event_handler, SDL_ControllerButtonEvent controller_button_event);

		/**
		 * @brief method called whenever a game condroller's axis is used
		 * @param event_handler: the EventHandler to which the GameControllerListener is registered to
		 * @param controller_axis_event: the SDL_ControllerAxisEvent triggered
		 *
		 * GameControllerListeners can be notified when a game controller's axis is
		 * used by overriding this method. GameControllerListeners need to
		 * register to an EventHandler to receive these events.
		 */
		virtual void on_game_controller_axis_motion (EventHandler *event_handler, SDL_ControllerAxisEvent controller_axis_event);

		/**
		 * @brief Returns the SDL_GameController
		 * @return SDL_GameController
		 */
		SDL_GameController* get_game_controller (void) const;
};

#endif