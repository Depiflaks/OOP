//
// Created by smmm on 10.05.2025.
//

#include "Circle.h"

Circle::Circle(const Point center, const double radius)
	: m_center(center)
	, m_radius(radius)
{
}

Circle::Circle(const Point center, const double radius, const Color outlineColor)
	: SolidShape(outlineColor)
	, m_center(center)
	, m_radius(radius)
{
}

Circle::Circle(const Point center, const double radius, const Color outlineColor, const Color fillColor)
	: SolidShape(outlineColor, fillColor)
	, m_center(center)
	, m_radius(radius)
{
}

double Circle::GetArea()
{
	return m_radius * m_radius * std::numbers::pi;
}

double Circle::GetPerimeter()
{
	return 2 * m_radius * std::numbers::pi;
}

std::string Circle::ToString()
{
	return "circle";
}

void Circle::Draw(ICanvas& canvas)
{
	canvas.DrawCircle(m_center, m_radius, GetOutlineColor());
	canvas.FillCircle(m_center, m_radius, GetFillColor());
}

std::ostream& operator<<(std::ostream& os, const Circle& circle)
{
	os << "circle " << circle.m_center << ' '
	   << circle.m_radius << ' ' << circle.GetOutlineColor() << ' ' << circle.GetFillColor();
	return os;
}

std::istream& operator>>(std::istream& is, Circle& circle)
{
	Color outlineColor, fillColor;
	is >> circle.m_center >> circle.m_radius >> outlineColor >> fillColor;
	circle.SetOutlineColor(outlineColor);
	circle.SetFillColor(fillColor);
	return is;
}

Point Circle::GetCenter() const
{
	return m_center;
}

double Circle::GetRadius() const
{
	return m_radius;
}