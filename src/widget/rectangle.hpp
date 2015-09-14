#ifndef RECTANGLE
#define RECTANGLE

/**
 * @file rectangle.hpp
 * @version 0.1
 */

#include "../window/window.hpp"

/**
 * @class Rectangle
 * @brief A rectangle shaped widget
 * @see Widget
 *
 * Rectangle is the simplest Widget: it only has a background color.
 */
class Rectangle : public Widget {
	public:
		/**
		 * @brief Constructor
		 */
		Rectangle ();
		
		/**
		 * @brief Constructor
		 * @param x: the x position of the Rectangle
		 * @param y: the y position of the Rectangle
		 * @param width: the width of the Rectangle
		 * @param height: the height of the Rectangle
		 */
		Rectangle (int x, int y, int width, int height);
		
		/**
		 * @brief Constructor
		 * @param position: the Position of the Widget
		 * @param dimension: the Dimension of the Widget
		 */
		Rectangle (Position &position, Dimension &dimension);
		
		/**
		 * @brief Copy constructor
		 */
		Rectangle (const Rectangle &rectangle);
		
		/**
		 * @brief Destructor
		 */
		~Rectangle ();

		/**
		 * @brief Draws the Rectangle in the Window
		 */
		void draw (void);
};

#endif