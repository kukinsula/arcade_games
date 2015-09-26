#ifndef __LABEL__
#define __LABEL__

/**
 * @file label.hpp
 * @version 0.1
 */

#include <string>

#include "SDL.h"
#include "SDL_ttf.h"

#include "rectangle.hpp"

/**
 * @class Label
 * @brief Simple widget to print text
 *
 * Label is a Widget which prints text when drawn.
 */
class Label : virtual public Rectangle {
	private:
		std::string text;
		TTF_Font *font;
		// Color;
		int font_size;

	public:
		/**
		 * @brief Constructor
		 * @param text: the Label's text
		 */
		Label (std::string text);
		
		/**
		 * @brief Constructor
		 * @param x: the Label's x Position
		 * @param y: the Label's y Position
		 * @param width: the Label's width Position
		 * @param height: the Label's height Position
		 * @param text: the Label's text
		 */
		Label (int x, int y, int width, int height, std::string text);

		/**
		 * @brief Constructor
		 * @param position: the Label's Position
		 * @param dimension: the Label's Dimension
		 * @param text: the Label's text
		 */
		Label (Position position, Dimension dimension, std::string text);

		/**
		 * @brief Copy constructor
		 * @param label: the Label to copy
		 */
		Label (const Label &label);

		/**
		 * @brief Destructor
		 */
		~Label ();

		/**
		 * @brief Draws a Label
		 *
		 * It first draws the background and then prints the text over it.
		 */
		void draw (void);

		/**
		 * @brief Sets the Label's text
		 * @param text: the new Label's text
		 */
		void set_text (std::string &text);

		/**
		 * @brief Returns the Label's text
		 * @return std::string
		 */
		std::string get_text (void) const;
};

/**
 * @brief Writes a Label through an ostream
 * @param os: the ostream to write into
 * @param label: the Label to write
 * @return ostream
 */
std::ostream& operator<<(std::ostream &os, const Label &label);

#endif