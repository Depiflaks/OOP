//
// Created by smmm on 08.05.2025.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Canvas/ICanvas.h"
#include "shape/solidShape/ISolidShape.h"

#include <string>

class Triangle : ISolidShape
{
public:
	double GetArea() override;
	double GetPerimeter() override;
	std::string ToString() override;
	ColorType GetOutlineColor() override;


};

#endif // TRIANGLE_H
