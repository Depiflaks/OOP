#include "shape/solidShape/triangle/Triangle.h"

#include <iostream>
//
// Created by smmm on 06.05.2025.
//
int main()
{
	Triangle t{ { 0, 0 }, { 0, 0 }, { 0, 0 } };
	std::cin >> t;
	std::cout << t << std::endl;
	return 0;
}