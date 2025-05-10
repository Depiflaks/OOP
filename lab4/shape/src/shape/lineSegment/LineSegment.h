//
// Created by smmm on 06.05.2025.
//

#ifndef LINE_SEGMENT_H
#define LINE_SEGMENT_H
#include "shape/IShape.h"

class LineSegment final : public IShape
{
public:
	double GetArea() override;
	double GetPerimeter() override;
	std::string ToString() override;
	ColorType GetOutlineColor() override;

	void Draw(ICanvas& canvas) override;

	Point GetStartPoint();
	Point GetEndPoint();
};

#endif // LINE_SEGMENT_H
