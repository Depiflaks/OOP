//
// Created by smmm on 10.05.2025.
//

#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape/solidShape/SolidShape.h"

class Circle final : SolidShape
{
public:
	double GetArea() override;
	double GetPerimeter() override;
	std::string ToString() override;

	void Draw(ICanvas& canvas) override;

	Point GetCenter();
	Point GetRadius();
};

#endif // CIRCLE_H
