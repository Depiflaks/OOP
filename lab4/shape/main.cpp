#include "shape/shapeReader/ShapeReader.h"
#include "shape/solidShape/triangle/Triangle.h"

//
// Created by smmm on 06.05.2025.
//

#include <iostream>

void PrintShape(const std::shared_ptr<Shape>& shape)
{
	if (shape == nullptr)
		std::cout << "No shapes available.\n";
	else
		shape->Print(std::cout);
}

int main()
{
	const auto shapes = ShapeReader::ReadShapes(std::cin);
	const auto maxAreaShape = GetShapeWithMaxArea(shapes);
	const auto maxPerimeterShape = GetShapeWithMaxPerimeter(shapes);
	std::cout << "\nShape with max area: \n"
			  << std::endl;
	PrintShape(maxAreaShape);
	std::cout << "\nShape with max perimeter: \n"
			  << std::endl;
	PrintShape(maxPerimeterShape);
	return 0;
}