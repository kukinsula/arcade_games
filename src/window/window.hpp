#ifndef __WINDOW__
#define __WINDOW__

/**
 * @file window.hpp
 * @version 0.1
 */

#include "SDL.h"

#include <string>
#include <vector>

class View;
#include "../event/event_handler.hpp"
#include "../util/dimension.hpp"

#define DEFAULT_WINDOW_WIDTH 480 /**< Default window width */
#define DEFAULT_WINDOW_HEIGHT 640 /**< Default window height */

/**
 * @class Window
 * @brief Simple window object to create simple programs
 * @see EventHandler
 * @see View
 *
 * Window links an EventHandler to a View.
 */
class Window {
	private:
		std::string title;
		Dimension dimension;
		EventHandler event_handler;
		SDL_Window *window;
		SDL_Renderer *renderer;
		View *view;

	public:
		/**
		 * @brief Constructor
		 * @param title: the Window's title
		 * @param width: the Window's width
		 * @param height: the Window's height
		 */
		Window (std::string title, int width = DEFAULT_WINDOW_WIDTH, int height = DEFAULT_WINDOW_HEIGHT);
		
		/**
		 * @brief Constructor
		 * @param title: the Window's title
		 * @param dimension: the Window's dimension
		 */
		Window (std::string title, Dimension &dimension);
		
		/**
		 * @brief Copy constructor
		 */
		Window (const Window &window);
		
		/**
		 * @brief Destructor
		 */
		~Window ();

		/**
		 * @brief Opens the Window
		 */
		void open (void);
		
		/**
		 * @brief Closes the Window
		 */
		void close (void);

		/**
		 * @brief Sets the Window's EventHandler
		 * @param event_handler: the new EventHandler
		 */
		void set_event_handler (EventHandler &event_handler);
		
		/**
		 * @brief Sets the Window's View
		 * @param view: the new View
		 */
		void set_view (View *view);

		/**
		 * @brief Returns the Window's EventHandler
		 * @return EventHandler
		 */
		EventHandler& get_event_handler (void);
		
		/**
		 * @brief Returns the Window's SDL_Renderer
		 * @return SDL_Renderer*
		 */
		SDL_Renderer* get_renderer (void) const;
		
		/**
		 * @brief Returns the Window's View
		 * @return View
		 */
		View* get_view (void) const;
		
		/**
		 * @brief Returns the Window's Dimension
		 * @return Dimension
		 */
		Dimension& get_dimension (void);

		/**
		 * @brief Returns the Window's SDL_Window*
		 * @return SDL_Window*
		 */
		SDL_Window* get_window (void) const;
};

#include "view.hpp"

#endif