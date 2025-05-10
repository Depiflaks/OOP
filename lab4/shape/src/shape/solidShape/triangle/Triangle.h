//
// Created by smmm on 08.05.2025.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Canvas/ICanvas.h"
#include "shape/solidShape/SolidShape.h"

#include <string>

class Triangle : SolidShape
{
public:
	double GetArea() override;
	double GetPerimeter() override;
	std::string ToString() override;
	ColorType GetOutlineColor() override;

	Point GetVertex1();
	Point GetVertex2();
	Point GetVertex3();
};

#endif // TRIANGLE_H
