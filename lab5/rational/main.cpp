//
// Created by smmm on 06.05.2025.
//

#include <cRational/CRational.h>
#include <iostream>
#include <numeric>
#include <ostream>

int main()
{
	CRational a(1, 2);
	CRational b(1, 3);
	std::cout << a + b << std::endl;
}