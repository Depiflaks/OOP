//
// Created by smmm on 08.05.2025.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape/solidShape/SolidShape.h"

#include <string>

class Triangle : public SolidShape
{
public:
	explicit Triangle(Point vertex1, Point vertex2, Point vertex3);
	explicit Triangle(Point vertex1, Point vertex2, Point vertex3, ColorType outlineColor);
	explicit Triangle(Point vertex1, Point vertex2, Point vertex3, ColorType outlineColor, ColorType fillColor);

	double GetArea() override;
	double GetPerimeter() override;
	std::string ToString() override;

	Point GetVertex1() const;
	Point GetVertex2() const;
	Point GetVertex3() const;

private:
	Point m_vertex1;
	Point m_vertex2;
	Point m_vertex3;
};

#endif // TRIANGLE_H
