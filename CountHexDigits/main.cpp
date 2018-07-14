/**
 *
 * Twoim zadaniem jest stworzyć program, który wczyta z pliku o formatowaniu (Patrz załącznik 1 [file_1.txt])) dane, i policzy kilka rzeczy.
 *
 * 1) ilość występujących (1, 2, 3, 4, ... 0)
 * 2) Ilość występujących (a,b,c,d,e,f)
 * 3) będzie wypisywał za każdym razem numer lini który analizuje za pomocą spdlog (https://github.com/gabime/spdlog) jako debug
 * 4) będzie wypisywał jako info każde znalezione 0 oraz z.
 * 5) Raz na 100 lini wypisze na konsoli ( używając też spdloga ) aktualnie znane liczby.
 *
 * EDIT
 *
 * Punkt 3,4 do pliku, punkt 5 do pliku oraz na ekran
 *
 * ~~Task by @TheMesoria (https://github.com/TheMesoria/)
 *
 */

#include <iostream>
#include <fstream>
#include "Program.h"

int main() {
	Program::start();

	return 0;
}
