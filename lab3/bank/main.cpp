//
// Created by smmm on 15.03.2025.
//

#include <iostream>

#include <ostream>

class I
{
public:
	virtual void foo()
	{
		std::cout << "I foo" << std::endl;
	};
};

class A : public I
{
private:
	void foo() override
	{
		std::cout << "A foo" << std::endl;
	}
};

int main(int argc, char* argv[])
{
	A a{};
	I* b = &a;
	b->foo();
	return 0;
}