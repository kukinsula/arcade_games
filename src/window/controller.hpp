#ifndef __CONTROLLER__
#define __CONTROLLER__

/**
 * @file controller.hpp
 * @version 0.1
 */

class View;

/**
 * @class Controller
 * @brief Catches all events to create interractions
 * @see Window
 * @see View
 *
 * MVC: Controller is responsible for listening to events
 * and create interractions in response.
 */
class Controller {
	private:
		View *view;

	public:
		/**
		 * @brief Constructor
		 */
		Controller ();
		
		/**
		 * @brief Copy constructor
		 */
		Controller (const Controller &controller);
		
		/**
		 * @brief Destructor
		 */
		~Controller ();

		/**
		 * @brief Returns the associated View
		 * @return View
		 */
		View* get_view (void) const;

		/**
		 * @brief Sets the associated View
		 * @param view: the new associated View
		 */
		void set_view (View *view);
};

#include "view.hpp"

#endif