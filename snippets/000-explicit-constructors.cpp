#include <iostream>

struct Test {
	int x;
	int y;
	int z;

	// Test(int x, int y, int z) : x(x), y(y), z(z) {}
	explicit Test(int x, int y, int z) : x(x), y(y), z(z) {}
};

Test f() {
	int a = 1;
	int b = 2;
	int c = 3;
	// return {a, b, c};
	return Test{a, b, c};
}

int main() {
	Test x = f();
	std::cout << x.x << " " << x.y << " " << x.z << std::endl;
}
