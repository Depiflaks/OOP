//
// Created by smmm on 08.05.2025.
//

#include "Triangle.h"
Triangle::Triangle(Point vertex1, Point vertex2, Point vertex3)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
	, SolidShape()
{
}

Triangle::Triangle(Point vertex1, Point vertex2, Point vertex3, ColorType outlineColor)
{
}
Triangle::Triangle(Point vertex1, Point vertex2, Point vertex3, ColorType outlineColor, ColorType fillColor)
{
}
double Triangle::GetArea()
{
}
double Triangle::GetPerimeter()
{
}
std::string Triangle::ToString()
{
}
ColorType Triangle::GetOutlineColor()
{
}

Point Triangle::GetVertex1()
{
	return m_vertex1;
}

Point Triangle::GetVertex2()
{
	return m_vertex2;
}

Point Triangle::GetVertex3()
{
	return m_vertex3;
}