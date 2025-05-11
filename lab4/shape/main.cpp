#include "shape/shapeReader/ShapeReader.h"
#include "shape/solidShape/triangle/Triangle.h"

#include <iostream>
//
// Created by smmm on 06.05.2025.
//
int main()
{
	const std::shared_ptr<Shape> shape = ShapeReader::ReadShape(std::cin);
	shape->Print(std::cout);
	// std::cout << shape;
	return 0;
}