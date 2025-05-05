//
// Created by smmm on 15.03.2025.
//

#include <iostream>

#include <ostream>

class Base
{
public:
	void BaseFoo()
	{
		std::cout << "BaseFoo" << std::endl;
	}
};

class IBase
{
public:
	virtual void BaseFoo() = 0;
};

class Bar : public IBase
	, public Base
{
public:
	void BarFoo()
	{
		std::cout << "BarFoo" << std::endl;
	}
};

int main(int argc, char* argv[])
{
	Bar bar{};

	return 0;
}