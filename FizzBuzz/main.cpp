#include <iostream>

void FizzBuzz() {
	int x;
	int y;
	for (int i = 1; i < 101; i++) {
		x = i/3;
		x *= 3;
		if (x == i) {
			std::cout<<"Fizz";
		}
		y = i/5;
		y *= 5;
		if (y == i) {
			std::cout<<"Buzz";
		}
		if (x != i && y != i) {
			std::cout<<i;
		}
		std::cout<<std::endl;
	}
}

int main(){
	FizzBuzz();

	return 0;
}
