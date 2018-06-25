//
// Created by barto on 25.06.18.
//

#ifndef COUNTHEXDIGITS_PROGRAM_H
#define COUNTHEXDIGITS_PROGRAM_H


#include <vector>
#include <string>
#include <fstream>

class Program {
private:
	Program();

	static std::ifstream file;
	static std::vector<unsigned long long> resultArray;

public:
	static void start();

private:
	static std::string askForPath(); // ask for path to file

	static void countCharacters(); // loop for every character from file and count it if hex digit

	static void printResult(); // print the result

};


#endif //COUNTHEXDIGITS_PROGRAM_H
