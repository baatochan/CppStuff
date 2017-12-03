#include <iostream>
#include <ctime>

#define numberOfPpl 88 //should ask user about that and allocate an array with new ;-;

int calculateChecksum() {
	int checksum = 0;

	for (int i = 1; i <= numberOfPpl ; i++) {
		checksum += i;
	}

	return checksum;
}

int main() {
	srand(time(0));

	int result[2][numberOfPpl];

	for (int i = 0; i < numberOfPpl; i++) {
		result[0][i] = i+1;
	}

	bool existsInTheArray = false;

	for (int i = 0; i < numberOfPpl; i++) {
		do {
			existsInTheArray = false;
			int randomPerson = rand() % numberOfPpl;
			randomPerson++;

			result[1][i] = randomPerson;

			if (randomPerson == i+1) existsInTheArray = true;

			for (int j = 0; j < i; j++) {
				if (randomPerson == result[1][j]) existsInTheArray = true;
			}
		} while (existsInTheArray);
	}

	for (int i = 0; i < numberOfPpl; i++) {
		std::cout<<result[0][i]<<" rysuje dla "<<result[1][i]<<std::endl;
	}

	std::cout<<std::endl;

	for (int i = 0; i < numberOfPpl; i++) {
		std::cout<<result[0][i]<<";"<<result[1][i]<<std::endl;
	}

	std::cout<<std::endl;

	std::cout<<"Suma kontrolna wynosi: "<< calculateChecksum()<<std::endl;

	return 0;
}
