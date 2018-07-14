//
// Created by barto on 25.06.18.
//

#include <iostream>
#include "Program.h"

Program::Program() {}

std::ifstream Program::file = {};
std::vector<unsigned long long> Program::resultArray = {}; // {16, 0} doesnt work...

unsigned long long Program::lineNumber = 1;

std::shared_ptr<spdlog::logger> Program::consoleLogger = spdlog::stdout_color_mt("consoleLogger");
std::shared_ptr<spdlog::logger> Program::fileLogger = nullptr;

bool Program::fileLog = false;

void Program::start() {
	std::string path;
	resultArray.resize(16);

	spdlog::set_pattern("%v");

	prepareFileLogger();

	path = askForPath();

	printLineNumber();

	countCharacters();

	printResult(-1);
}

void Program::prepareFileLogger() {
	try {
		fileLogger = spdlog::basic_logger_mt("fileLogger", "log.txt");
	} catch (const spdlog::spdlog_ex& ex) {
		std::cerr << "Initializacja logow do pliku sie nie powiodla. Aplikacja kontynuuje." << std::endl;
	}

	fileLog = true;

	fileLogger->info("------------------------------------------------------------");
	fileLogger->info("--------------------------- START --------------------------");
	fileLogger->info("------------------------------------------------------------");
}

std::string Program::askForPath() {
	std::string path;
	bool error = false;

	do {
		if (error)
			std::cerr << "Nie ma takiego pliku!" << std::endl;

		std::cout << "Podaj sciezke do pliku: ";
		getline(std::cin, path);

		file.open(path, std::ios::in);

		error = true;
	} while (!file.is_open());

	return path;
}

void Program::countCharacters() {
	char characterFromFile;

	while (file.get(characterFromFile))
		switch (characterFromFile) {
			// ughhhh, cant think of better way to do it

			case '0':
				resultArray[0]++;
				printFoundedChar('0');
				break;

			case '1':
				resultArray[1]++;
				break;

			case '2':
				resultArray[2]++;
				break;

			case '3':
				resultArray[3]++;
				break;

			case '4':
				resultArray[4]++;
				break;

			case '5':
				resultArray[5]++;
				break;

			case '6':
				resultArray[6]++;
				break;

			case '7':
				resultArray[7]++;
				break;

			case '8':
				resultArray[8]++;
				break;

			case '9':
				resultArray[9]++;
				break;

			case 'a':
			case 'A':
				resultArray[10]++;
				break;

			case 'b':
			case 'B':
				resultArray[11]++;
				break;

			case 'c':
			case 'C':
				resultArray[12]++;
				break;

			case 'd':
			case 'D':
				resultArray[13]++;
				break;

			case 'e':
			case 'E':
				resultArray[14]++;
				break;

			case 'f':
			case 'F':
				resultArray[15]++;
				break;

			case 'z':
				printFoundedChar('z');
				break;

			case 'Z':
				printFoundedChar('Z');
				break;

			case '\n':
				if (lineNumber % 100 == 0) {
					printResult(lineNumber);
				}

				lineNumber++;

				printLineNumber();
				break;

			default:
				// ¯\_(ツ)_/¯
				break;

		}
}

void Program::printFoundedChar(char c) {
	if (fileLog)
		fileLogger->info("Znaleziono '{}' w lini {}.", c, lineNumber);
}

void Program::printLineNumber() {
	fileLogger->info("Analiza lini {}.", lineNumber);
}

void Program::printResult(unsigned long long position) {
	if (fileLog) {
		if (position == -1) {
			fileLogger->info("----------------------------------------");
			fileLogger->info("------------ KONCOWY WYNIK -------------", position);
			fileLogger->info("----------------------------------------");
		} else {
			fileLogger->info("----------------------------------------");
			fileLogger->info("Wynik po lini {}:", position);
			fileLogger->info("----------------------------------------");
		}
		fileLogger->info("'0': {}", resultArray[0]);
		fileLogger->info("'1': {}", resultArray[1]);
		fileLogger->info("'2': {}", resultArray[2]);
		fileLogger->info("'3': {}", resultArray[3]);
		fileLogger->info("'4': {}", resultArray[4]);
		fileLogger->info("'5': {}", resultArray[5]);
		fileLogger->info("'6': {}", resultArray[6]);
		fileLogger->info("'7': {}", resultArray[7]);
		fileLogger->info("'8': {}", resultArray[8]);
		fileLogger->info("'9': {}", resultArray[9]);
		fileLogger->info("'a': {}", resultArray[10]);
		fileLogger->info("'b': {}", resultArray[11]);
		fileLogger->info("'c': {}", resultArray[12]);
		fileLogger->info("'d': {}", resultArray[13]);
		fileLogger->info("'e': {}", resultArray[14]);
		fileLogger->info("'f': {}", resultArray[15]);
	}

	if (position == -1) {
		consoleLogger->info("----------------------------------------");
		consoleLogger->info("------------ KONCOWY WYNIK -------------", position);
		consoleLogger->info("----------------------------------------");
	} else {
		consoleLogger->info("----------------------------------------");
		consoleLogger->info("Wynik po lini {}:", position);
		consoleLogger->info("----------------------------------------");
	}
	consoleLogger->info("'0': {}", resultArray[0]);
	consoleLogger->info("'1': {}", resultArray[1]);
	consoleLogger->info("'2': {}", resultArray[2]);
	consoleLogger->info("'3': {}", resultArray[3]);
	consoleLogger->info("'4': {}", resultArray[4]);
	consoleLogger->info("'5': {}", resultArray[5]);
	consoleLogger->info("'6': {}", resultArray[6]);
	consoleLogger->info("'7': {}", resultArray[7]);
	consoleLogger->info("'8': {}", resultArray[8]);
	consoleLogger->info("'9': {}", resultArray[9]);
	consoleLogger->info("'a': {}", resultArray[10]);
	consoleLogger->info("'b': {}", resultArray[11]);
	consoleLogger->info("'c': {}", resultArray[12]);
	consoleLogger->info("'d': {}", resultArray[13]);
	consoleLogger->info("'e': {}", resultArray[14]);
	consoleLogger->info("'f': {}", resultArray[15]);
}
