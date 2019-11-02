#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

void showStartMsg() {
	std::cout << "Aplikacja pomaga wylosować osoby do zabawy Secret Santa." << std::endl;
	std::cout << "Przygotuj listę wszystkich osób, które biorą udział w zabawie i nadaj każdej z nich unikalny numer."
	          << std::endl;
	std::cout << "Program na koniec poda ci listę w stylu 'Osoba nr. X przygotowuje prezent dla Osoba nr. Y'."
	          << std::endl;
	std::cout << "Pozwoli ci to na szybką podmianę wartości 'Osoba nr. X' na imię/pseudonim osoby,"
	          << " przy tworzeniu listy do ogłoszenia wyników." << std::endl;
}

int askForNoOfParticipants() {
	std::cout << std::endl << "Podaj liczbę członków zabawy (całkowita, dodatnia, inaczej program się scrashuje): ";

	int numberOfParticipants;
	std::cin >> numberOfParticipants;

	return numberOfParticipants;
}

bool checkIfAlreadyGifted(const std::vector<int>& pairs, int person) {
	auto result = std::find(pairs.begin(), pairs.end(), person);

	return result != pairs.end();
}

std::vector<int> shuffle(int numberOfParticipants) {
	std::random_device seed;
	std::mt19937 randomGenerator(seed());
	std::uniform_int_distribution<> rangeTransformer(1, numberOfParticipants);

	std::vector<int> results;
	results.resize(numberOfParticipants);

	do {
		for (int i = 0; i < numberOfParticipants; ++i) {
			int giftFor;

			do {
				giftFor = rangeTransformer(randomGenerator);
			} while ((giftFor == i + 1 && i + 1 != numberOfParticipants) || checkIfAlreadyGifted(results, giftFor));
			// it is possible that the last person can be shuffled only with themselves.

			results[i] = giftFor;
		}
	} while (results[numberOfParticipants - 1] == numberOfParticipants);
	// it is possible that the last person will be shuffled with themselves, so to prevent that the shuffle is done again.
	// it is random situation and there is no possibility that for any number it will always be like that.

	return results;
}

void printResults(const std::vector<int>& results) {
	std::cout << std::endl << std::endl << "Wyniki:" << std::endl;

	for (unsigned long i = 0; i < results.size(); ++i) {
		std::cout << "Osoba nr. " << i + 1 << " przygotowuje prezent dla Osoba nr. " << results[i] << std::endl;
	}
}

int calculateChecksum(int numberOfParticipants) {
	int sum = 0;

	for (int i = 0; i < numberOfParticipants; ++i) {
		sum += i + 1;
	}

	return sum;
}

int calculateChecksum(const std::vector<int>& results) {
	int sum = std::accumulate(results.begin(), results.end(), 0);

	return sum;
}

void printChecksums(int numberOfParticipants, const std::vector<int>& results) {
	std::cout << std::endl << "Sumy kontrolne wynoszą: " << calculateChecksum(numberOfParticipants) << " i "
	          << calculateChecksum(results) << std::endl;
};

bool askToRestart() {
	std::cout << "Czy chcesz losować jeszcze raz? [t/n]: ";
	char input;
	std::cin >> input;

	return (input == 'T' || input == 't');
}

int main() {
	bool restart;
	do {
		showStartMsg();
		int numberOfParticipants = askForNoOfParticipants();
		auto results = shuffle(numberOfParticipants);
		printResults(results);
		printChecksums(numberOfParticipants, results);
		restart = askToRestart();
	} while (restart);
}
