#include <memory>

struct Base {
	virtual ~Base() = default;
};

struct Derived : Base {
	Derived() : x(0) {};
	Derived(int x) : x(x) {};

	int x;
};

int main() {
	Base* ptr1 = new Derived();
	std::unique_ptr<Base> sptr1 = std::make_unique<Derived>();

	Base* ptr2 = new Derived();
	std::shared_ptr<Base> sptr2 = std::make_shared<Derived>();

	Base* ptr3 = new Derived(420);
	std::unique_ptr<Base> sptr3 = std::make_unique<Derived>(420);
	std::shared_ptr<Base> sptr4 = std::make_shared<Derived>(420);

	delete ptr1;
	delete ptr2;
	delete ptr3;

	return 0;
}
