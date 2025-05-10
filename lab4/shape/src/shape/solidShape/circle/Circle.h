//
// Created by smmm on 10.05.2025.
//

#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape/solidShape/ISolidShape.h"

class Circle final : ISolidShape
{
	double GetArea() override;
	double GetPerimeter() override;
	std::string ToString() override;

	ColorType GetOutlineColor() override;
	ColorType GetFillColor() override;

	void Draw(ICanvas& canvas) override;

	Point GetCenter();
	Point GetRadius();
};

#endif // CIRCLE_H
