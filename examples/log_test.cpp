#include "log_test.hpp"

#include "../src/log/log.hpp"
#include "../src/log/log_message.hpp"
#include "../src/log/console_logger.hpp"

#include "../src/util/position.hpp"
#include "../src/util/dimension.hpp"
#include "../src/util/color.hpp"

 #include <sstream>

int main (void) {
	ConsoleLogger *logger = new ConsoleLogger(info);
	Position position(10, 1);
	Dimension dimension(100, 42);
	std::ostringstream oss;

	Log::add_logger(logger);

	Log::write(
		LOG(info, "test\n") <<
			"\t512 * 2 = " << 2 * 512 << "\n" <<
			"\t2.4 / 2 = " << 2.4f / 2 << "\n" <<
			"\t1 == 1 ? " << (1 == 1) << "\n" <<
			"\tposition = " << position << "\n" <<
			"\tdimension = " << dimension << "\n"
			"\tRED = " << Color::RED
	);

	// // MSG(info, "THIS IS A TEST ! 1 2 1 2");
	// Log::write(message);

	// oss << position;
	// MSG(info, oss.str() );
}