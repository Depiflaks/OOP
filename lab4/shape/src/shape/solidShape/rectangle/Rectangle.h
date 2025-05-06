//
// Created by smmm on 06.05.2025.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Canvas/ICanvas.h"
#include "shape/solidShape/ISolidShape.h"

#include <string>

class Rectangle : public ISolidShape
{
public:
	double GetArea() override;
	double GetPerimeter() override;
	std::string ToString() override;
	ColorType GetOutlineColor() override;
	ColorType GetFillColor() override;

	Point GetLeftTop();
	Point GetRightBottom();
	Point GetWidth();
	Point GetHeight();
};

#endif // RECTANGLE_H
