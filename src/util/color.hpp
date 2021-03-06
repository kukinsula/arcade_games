#ifndef __COLOR__
#define __COLOR__

#include <string>

/**
 * @file color.hpp
 * @version 0.1
 */

/**
 * @class Color
 * @brief Represents an RGBA color.
 *
 * Color holds an amount of red, blue green and alpha.
 */
class Color {
	private:
		int red, green, blue, alpha;

	public:
		/**
		 * @brief Constructor
		 */
		Color ();
		
		/**
		 * @brief Constructor
		 * @param red: the amount of red
		 * @param blue: the amount of blue
		 * @param green: the amount of green
		 * @param alpha: the amount of alpha
		 */
		Color (int red, int green, int blue, int alpha = 255);

		/**
		 * @brief Copy constructor
		 */
		Color (const Color &color);
		
		/**
		 * @brief Destructor
		 */
		~Color ();

		static Color RED; /**< Predefined red Color */
		static Color GREEN; /**< Predefined green Color */
		static Color BLUE; /**< Predefined blue Color */
		static Color BLACK; /**< Predefined black Color */
		static Color WHITE; /**< Predefined white Color */
		static Color LIGHT_GRAY; /**< Predefined light gray Color */
		static Color STRONG_GRAY; /**< Predefined strong gray Color */

		/**
		 * @brief Sets the amount of red
		 * @param red: the new amount of red
		 */
		void set_red (int red);
		
		/**
		 * @brief Sets the amount of green
		 * @param green: the new amount of green
		 */
		void set_green (int green);
		
		/**
		 * @brief Sets the amount of blue
		 * @param blue: the new amount of blue
		 */
		void set_blue (int blue);
		
		/**
		 * @brief Sets the amount of alpha
		 * @param alpha: the new amount of alpha
		 */
		void set_alpha (int alpha);

		/**
		 * @brief Returns the amount of red
		 * @return int
		 */
		int get_red (void) const;
		
		/**
		 * @brief Returns the amount of green
		 * @return int
		 */
		int get_green (void) const;

		/**
		 * @brief Returns the amount of blue
		 * @return int
		 */
		int get_blue (void) const;

		/**
		 * @brief Returns the amount of alpha
		 * @return int
		 */
		int get_alpha (void) const;
};

/**
 * @brief Writes a Color into an ostream
 * @param os: the ostream in which to write
 * @param color: the Color to write
 */
std::ostream& operator<< (std::ostream &os, const Color &color);

#endif