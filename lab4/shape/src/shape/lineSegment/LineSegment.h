//
// Created by smmm on 06.05.2025.
//

#ifndef LINESEGMENT_H
#define LINESEGMENT_H
#include "shape/IShape.h"

class LineSegment : public IShape
{
	double GetArea() override;
	double GetPerimeter() override;
	std::string ToString() override;
	ColorType GetOutlineColor() override;

	void Draw(ICanvas& canvas) override;

	Point GetStartPoint();
	Point GetEndPoint();
};

#endif // LINESEGMENT_H
