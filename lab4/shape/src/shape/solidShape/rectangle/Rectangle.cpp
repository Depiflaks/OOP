//
// Created by smmm on 06.05.2025.
//

#include "Rectangle.h"

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