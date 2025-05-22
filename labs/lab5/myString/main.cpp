//
// Created by smmm on 16.05.2025.
//

#include "MyString.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>

int main()
{
	MyString mystring{"5957325470"};
	std::ranges::sort(mystring);
	std::cout << mystring << std::endl;
}