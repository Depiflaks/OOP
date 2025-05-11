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

double Circle::GetArea() const
{
	return m_radius * m_radius * std::numbers::pi;
}

double Circle::GetPerimeter() const
{
	return 2 * m_radius * std::numbers::pi;
}

std::string Circle::ToString() const
{
	return "Circle";
}

void Circle::Draw(ICanvas& canvas)
{
	canvas.DrawCircle(m_center, m_radius, GetOutlineColor());
	canvas.FillCircle(m_center, m_radius, GetFillColor());
}

std::ostream& operator<<(std::ostream& os, const Circle& circle)
{
    os << "Shape: " << circle.ToString() << '\n';
    os << "Center: " << circle.GetCenter() << '\n';
    os << "Radius: " << circle.GetRadius() << '\n';

    if (circle.GetOutlineColor().GetRGBA() != k_empty.GetRGBA())
        os << "Outline Color: " << circle.GetOutlineColor() << '\n';

    if (circle.GetFillColor().GetRGBA() != k_empty.GetRGBA())
        os << "Fill Color: " << circle.GetFillColor() << '\n';

    os << "Perimeter: " << circle.GetPerimeter() << '\n';
    os << "Area: " << circle.GetArea() << '\n';
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