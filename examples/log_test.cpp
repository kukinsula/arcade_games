#include "log_test.hpp"

#include "../src/log/log.hpp"
#include "../src/log/log_message.hpp"
#include "../src/log/console_logger.hpp"

#include "../src/util/position.hpp"

 #include <sstream>

int main (void) {
	ConsoleLogger *logger = new ConsoleLogger(info);
	Position position(10, 1);
	std::ostringstream oss;

	Log::add_logger(logger);

	Log::write(LOG(info, "test") << " " << 1024 << " " << 1.2f << " " << true);

	// // MSG(info, "THIS IS A TEST ! 1 2 1 2");
	// Log::write(message);

	// oss << position;
	// MSG(info, oss.str() );
}