//
// Created by smmm on 06.05.2025.
//

#include "LineSegment.h"

LineSegment::LineSegment(const Point start, const Point end)
	: m_startPoint(start)
	, m_endPoint(end)
{
}

LineSegment::LineSegment(const Point start, const Point end, const Color outlineColor)
	: Shape(outlineColor)
	, m_startPoint(start)
	, m_endPoint(end)
{
}

double LineSegment::GetArea() const
{
	return 0;
}

double LineSegment::GetPerimeter() const
{
	return Point::Distance(m_startPoint, m_endPoint);
}

std::string LineSegment::ToString() const
{
	return "lineSegment";
}

void LineSegment::Draw(ICanvas& canvas)
{
	canvas.DrawLine(m_startPoint, m_endPoint, GetOutlineColor());
}

std::ostream& operator<<(std::ostream& os, const LineSegment& lineSegment)
{
	os << "Shape: " << lineSegment.ToString() << '\n';
	os << "Start Point: " << lineSegment.GetStartPoint() << '\n';
	os << "End Point: " << lineSegment.GetEndPoint() << '\n';
	os << "Outline Color: " << lineSegment.GetOutlineColor() << '\n';
	os << "Perimeter: " << lineSegment.GetPerimeter() << '\n';
	return os;
}

std::istream& operator>>(std::istream& is, LineSegment& lineSegment)
{
	Color outlineColor, fillColor;
	is >> lineSegment.m_startPoint >> lineSegment.m_endPoint >> outlineColor;
	lineSegment.SetOutlineColor(outlineColor);
	return is;
}

Point LineSegment::GetStartPoint() const
{
	return m_startPoint;
}

Point LineSegment::GetEndPoint() const
{
	return m_endPoint;
}