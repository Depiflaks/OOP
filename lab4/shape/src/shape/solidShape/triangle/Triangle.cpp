//
// Created by smmm on 08.05.2025.
//

#include "Triangle.h"

Triangle::Triangle(const Point vertex1, const Point vertex2, const Point vertex3)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}

Triangle::Triangle(const Point vertex1, const Point vertex2, const Point vertex3, const Color outlineColor)
	: SolidShape(outlineColor)
	, m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}

Triangle::Triangle(const Point vertex1, const Point vertex2, const Point vertex3, const Color outlineColor, const Color fillColor)
	: SolidShape(outlineColor, fillColor)
	, m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}

void Triangle::Draw(ICanvas& canvas)
{
	canvas.DrawPolygon({ m_vertex1, m_vertex2, m_vertex3 }, GetOutlineColor());
	canvas.FillPolygon({ m_vertex1, m_vertex2, m_vertex3 }, GetFillColor());
}

double Triangle::GetArea() const
{
	return std::abs(
		(m_vertex1.x * (m_vertex2.y - m_vertex3.y) + m_vertex2.x * (m_vertex3.y - m_vertex1.y) + m_vertex3.x * (m_vertex1.y - m_vertex2.y)) * 0.5);
}

double Triangle::GetPerimeter() const
{
	return Point::Distance(m_vertex1, m_vertex2) + Point::Distance(m_vertex2, m_vertex3) + Point::Distance(m_vertex3, m_vertex1);
}

std::string Triangle::ToString() const
{
	return "Triangle";
}

std::ostream& operator<<(std::ostream& os, const Triangle& triangle)
{
	os << "Shape: " << triangle.ToString() << '\n';
	os << "Vertex 1: " << triangle.GetVertex1() << '\n';
	os << "Vertex 2: " << triangle.GetVertex2() << '\n';
	os << "Vertex 3: " << triangle.GetVertex3() << '\n';

	if (triangle.GetOutlineColor().GetRGBA() != k_empty.GetRGBA())
		os << "Outline Color: " << triangle.GetOutlineColor() << '\n';

	if (triangle.GetFillColor().GetRGBA() != k_empty.GetRGBA())
		os << "Fill Color: " << triangle.GetFillColor() << '\n';

	os << "Perimeter: " << triangle.GetPerimeter() << '\n';
	os << "Area: " << triangle.GetArea() << '\n';
	return os;
}

std::istream& operator>>(std::istream& is, Triangle& triangle)
{
	Color outlineColor, fillColor;
	is >> triangle.m_vertex1 >> triangle.m_vertex2 >> triangle.m_vertex3 >> outlineColor >> fillColor;
	triangle.SetOutlineColor(outlineColor);
	triangle.SetFillColor(fillColor);
	return is;
}

Point Triangle::GetVertex1() const
{
	return m_vertex1;
}

Point Triangle::GetVertex2() const
{
	return m_vertex2;
}

Point Triangle::GetVertex3() const
{
	return m_vertex3;
}