#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::string path;
	bool error = false;

	std::ifstream file;

	do {
		if (error)
			std::cout << "Nie ma takiego pliku!" << std::endl;

		std::cout << "Podaj sciezke do pliku: ";
		getline(std::cin, path);

		file.open(path, std::ios::in);

		error = true;
	} while (!file.is_open());

	char characterFromFile;

	while (file.get(characterFromFile))
		std::cout << characterFromFile;


	return 0;
}
