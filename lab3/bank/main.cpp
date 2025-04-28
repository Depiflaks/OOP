#include "src/bank/Bank.h"

#include <iostream>
#include <ostream>
//
// Created by smmm on 15.03.2025.
//

class A
{
public:
	void publicA()
	{
		std::cout << "publicA" << std::endl;
	}

protected:
	void protectedA()
	{
		std::cout << "protectedA" << std::endl;
	}

private:
	void privateA()
	{
		std::cout << "privateA" << std::endl;
	}
};

class B : protected A
{
public:
	B()
	{
		std::cout << "B{B}" << std::endl;
		protectedA();
	}
private:
	void privateB()
	{
		protectedA();
	}
};

int main(int argc, char* argv[])
{
	B b{};
	return 0;
}