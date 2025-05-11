#include "shape/shapeReader/ShapeReader.h"
#include "shape/solidShape/triangle/Triangle.h"

#include <iostream>
//
// Created by smmm on 06.05.2025.
//

int main()
{
	const auto shapes = ShapeReader::ReadShapes(std::cin);
	for (const auto& shape : shapes)
		std::cout << shape << '\n' << '\n';
	return 0;
}