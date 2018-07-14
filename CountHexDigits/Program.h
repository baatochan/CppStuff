//
// Created by barto on 25.06.18.
//

#ifndef COUNTHEXDIGITS_PROGRAM_H
#define COUNTHEXDIGITS_PROGRAM_H


#include <vector>
#include <string>
#include <fstream>
#include "spdlog/include/spdlog/spdlog.h"
#include "spdlog/include/spdlog/sinks/stdout_sinks.h"
#include "spdlog/include/spdlog/sinks/file_sinks.h"

class Program {
private:
	Program();

	static std::ifstream file;
	static std::vector<unsigned long long> resultArray;

	static unsigned long long lineNumber;

	static std::shared_ptr<spdlog::logger> consoleLogger;
	static std::shared_ptr<spdlog::logger> fileLogger;

	static bool fileLog;

public:
	static void start();

private:
	static void prepareFileLogger(); // initialization of file logger

	static std::string askForPath(); // ask for path to file

	static void countCharacters(); // loop for every character from file and count it if hex digit

	static void printFounded0(); // print line number with 0
	static void printFoundedZ(); // print line number with z/Z
	static void printLineNumber(); // print line number
	static void printResult(); // print the result

};


#endif //COUNTHEXDIGITS_PROGRAM_H
