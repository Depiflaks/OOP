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

Triangle::Triangle(const Point vertex1, const Point vertex2, const Point vertex3, const ColorType outlineColor)
	: SolidShape(outlineColor)
	, m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}

Triangle::Triangle(const Point vertex1, const Point vertex2, const Point vertex3, const ColorType outlineColor, const ColorType fillColor)
	: SolidShape(outlineColor, fillColor)
	, m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}

double Triangle::GetArea()
{
	return std::abs(
		(m_vertex1.x * (m_vertex2.y - m_vertex3.y) + m_vertex2.x * (m_vertex3.y - m_vertex1.y) + m_vertex3.x * (m_vertex1.y - m_vertex2.y)) * 0.5);
}

double Triangle::GetPerimeter()
{
	return Point::Distance(m_vertex1, m_vertex2) + Point::Distance(m_vertex2, m_vertex3) + Point::Distance(m_vertex3, m_vertex1);
}

std::string Triangle::ToString()
{
	return "triangle " + std::to_string(GetVertex1()) + " ";
}

ColorType Triangle::GetOutlineColor()
{
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