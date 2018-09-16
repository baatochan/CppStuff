#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_sinks.h"

int main() {
	auto consoleLogger = spdlog::stdout_color_mt("consoleLogger");
	spdlog::set_pattern("%v");

	consoleLogger->info("Hello, World!");
	
	return 0;
}
