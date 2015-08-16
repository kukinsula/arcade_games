#ifndef COLOR
#define COLOR

class Color {
	private:
		int r, g, b;

	public:
		Color (int r, int g, int b);
		Color ();

		static Color RED;
		static Color GREEN;
		static Color BLUE;
		static Color BLACK;
		static Color WHITE;
		static Color LIGHT_GRAY;
		static Color STRONG_GRAY;

		int get_red () const;
		int get_green () const;
		int get_blue () const;
};

#endif