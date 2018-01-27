#include <iostream>
#include <conio.h>

void changeNumberValueByUpAndDownArrows (int &number) {
    int keyPressed = 0;
    while (true) { //zczytuj w petli klawisze az nie zostanie osiagniety warunek przerwania
        std::cout<<"Wartosc: "<<number<<std::endl; //wypisz aktualna wartosc

        while (true) { //wykonuj sie dopoki jakikolwiek klawisz nie zostanie wcisniety (nie dziala na klawisze o kodzie 0 i 224)
            keyPressed = getch();
            if (keyPressed != 0 && keyPressed != 224) { //getch zanim wczyta klawisz strzalki najpierw wczytuje wartosc 0 lub 224 (zalezy czy strzalka zwykla czy na numpadzie)
                break;
            }
        }

        if (keyPressed == 72) { //gdy strzalka do gory
            number++;
        } else if (keyPressed == 80) { // gdy strzalka w dol
            number--;
        }

        if (number == 10) { //warunek przerwania - number osiaga wartosc 10
            std::cout << "Wartosc: " << number << std::endl; //wypisz wartosc po raz ostatni
            break;
        }
    }
}

int main(){
    int number = 0;
    changeNumberValueByUpAndDownArrows(number); //wywoalnie funkcji
    return 0;
}