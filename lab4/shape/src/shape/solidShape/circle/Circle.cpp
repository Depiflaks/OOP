//
// Created by smmm on 10.05.2025.
//

#include "Circle.h"
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

Point Circle::GetCenter() const
{
	return m_center;
}

double Circle::GetRadius() const
{
	return m_radius;
}