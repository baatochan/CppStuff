#include <iostream>
#include <fstream>

int main() {
	// initialization of needed vars
	int resultArray[16] = {0};

	std::string path;
	bool error = false;

	std::ifstream file;

	char characterFromFile;

	// ask for path to file
	do {
		if (error)
			std::cout << "Nie ma takiego pliku!" << std::endl;

		std::cout << "Podaj sciezke do pliku: ";
		getline(std::cin, path);

		file.open(path, std::ios::in);

		error = true;
	} while (!file.is_open());

	// loop for every character from file and count it if hex digit
	while (file.get(characterFromFile))
		switch (characterFromFile) {
			// ughhhh, cant think of better way to do it

			case '0':
				resultArray[0]++;
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

			default:
				// ¯\_(ツ)_/¯
				break;

		}

	// print the result
	std::cout << "Amount of: " << std::endl;
	std::cout << "'0': " << resultArray[0] << std::endl;
	std::cout << "'1': " << resultArray[1] << std::endl;
	std::cout << "'2': " << resultArray[2] << std::endl;
	std::cout << "'3': " << resultArray[3] << std::endl;
	std::cout << "'4': " << resultArray[4] << std::endl;
	std::cout << "'5': " << resultArray[5] << std::endl;
	std::cout << "'6': " << resultArray[6] << std::endl;
	std::cout << "'7': " << resultArray[7] << std::endl;
	std::cout << "'8': " << resultArray[8] << std::endl;
	std::cout << "'9': " << resultArray[9] << std::endl;
	std::cout << "'a': " << resultArray[10] << std::endl;
	std::cout << "'b': " << resultArray[11] << std::endl;
	std::cout << "'c': " << resultArray[12] << std::endl;
	std::cout << "'d': " << resultArray[13] << std::endl;
	std::cout << "'e': " << resultArray[14] << std::endl;
	std::cout << "'f': " << resultArray[15] << std::endl;
	
	return 0;
}
