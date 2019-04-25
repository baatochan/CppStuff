#include <iostream>

enum class EC { E0, E1, E2 };
enum class EC2 { A=-1, B, C };

int main() {
	EC e = EC::E1;
	EC2 ec = static_cast<EC2>(e);

	if (ec == EC2::C) {
		std::cout << "ec == EC2::C" << std::endl;
	} else {
		std::cout << "ec != EC2::C" << std::endl;
	}

	return 0;
}
