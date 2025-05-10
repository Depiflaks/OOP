//
// Created by smmm on 06.05.2025.
//

#include "Rectangle.h"

Rectangle::Rectangle(const Point leftTop, const double width, const double height)
	: SolidShape(k_black)
	, m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
{
}

Rectangle::Rectangle(const Point leftTop, const double width, const double height, const Color outlineColor)
	: SolidShape(outlineColor)
	, m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
{
}

Rectangle::Rectangle(const Point leftTop, const double width, const double height, const Color outlineColor, const Color fillColor)
	: SolidShape(outlineColor, fillColor)
	, m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
{
}

double Rectangle::GetArea()
{
	return m_width * m_height;
}

double Rectangle::GetPerimeter()
{
	return 2 * (m_width + m_height);
}

std::string Rectangle::ToString()
{
	return "rectangle";
}

void Rectangle::Draw(ICanvas& canvas)
{
	canvas.DrawPolygon({
						   m_leftTop,
						   { m_leftTop.x + m_width, m_leftTop.y },
						   { m_leftTop.x + m_width, m_leftTop.y + m_height },
						   { m_leftTop.x, m_leftTop.y + m_height },
					   },
		GetOutlineColor());
	canvas.FillPolygon({
						   m_leftTop,
						   { m_leftTop.x + m_width, m_leftTop.y },
						   { m_leftTop.x + m_width, m_leftTop.y + m_height },
						   { m_leftTop.x, m_leftTop.y + m_height },
					   },
		GetFillColor());
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle)
{
	os << "rectangle " << rectangle.m_leftTop << ' '
	   << rectangle.m_width << ' ' << rectangle.m_height << ' '
	   << rectangle.GetOutlineColor() << ' ' << rectangle.GetFillColor();
	return os;
}

std::istream& operator>>(std::istream& is, Rectangle& rectangle)
{
	Color outlineColor, fillColor;
	is >> rectangle.m_leftTop >> rectangle.m_width >> rectangle.m_height >> outlineColor >> fillColor;
	rectangle.SetOutlineColor(outlineColor);
	rectangle.SetFillColor(fillColor);
	return is;
}

Point Rectangle::GetLeftTop() const
{
	return m_leftTop;
}

Point Rectangle::GetRightBottom() const
{
	return { m_leftTop.x + m_width, m_leftTop.y + m_height };
}

double Rectangle::GetWidth() const
{
	return m_width;
}

double Rectangle::GetHeight() const
{
	return m_height;
}