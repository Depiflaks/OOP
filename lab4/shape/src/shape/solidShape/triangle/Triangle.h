//
// Created by smmm on 08.05.2025.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape/solidShape/SolidShape.h"

#include <string>

class Triangle final : public SolidShape
{
public:
	explicit Triangle(Point vertex1, Point vertex2, Point vertex3);
	explicit Triangle(Point vertex1, Point vertex2, Point vertex3, Color outlineColor);
	explicit Triangle(Point vertex1, Point vertex2, Point vertex3, Color outlineColor, Color fillColor);

	void Draw(ICanvas& canvas) override;

	double GetArea() override;
	double GetPerimeter() override;
	std::string ToString() override;

	friend std::ostream& operator<<(std::ostream& os, const Triangle& triangle);
    friend std::istream& operator>>(std::istream& is, Triangle& triangle);

	[[nodiscard]] Point GetVertex1() const;
	[[nodiscard]] Point GetVertex2() const;
	[[nodiscard]] Point GetVertex3() const;

private:
	Point m_vertex1;
	Point m_vertex2;
	Point m_vertex3;
};

#endif // TRIANGLE_H
