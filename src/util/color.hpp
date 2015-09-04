#ifndef COLOR
#define COLOR

class Color {
	private:
		int red, green, blue, alpha;

	public:
		Color ();
		Color (int red, int green, int blue, int alpha = 255);
		Color (const Color &color);
		~Color ();

		static Color RED;
		static Color GREEN;
		static Color BLUE;
		static Color BLACK;
		static Color WHITE;
		static Color LIGHT_GRAY;
		static Color STRONG_GRAY;

		void set_red (int red);
		void set_green (int green);
		void set_blue (int blue);
		void set_alpha (int alpha);

		int get_red (void) const;
		int get_green (void) const;
		int get_blue (void) const;
		int get_alpha (void) const;
};

#endif