//
// Created by smmm on 06.05.2025.
//

#include "SolidShape.h"

SolidShape::SolidShape()
	: Shape(k_black)
	, m_fillColor(k_black)
{
}

SolidShape::SolidShape(const ColorType outlineColor, const ColorType fillColor)
	: Shape(outlineColor)
	, m_fillColor(fillColor)
{
}

SolidShape::SolidShape(const ColorType outlineColor)
	: Shape(outlineColor)
	, m_fillColor(k_black)
{
}

ColorType SolidShape::GetFillColor() const
{
	return m_fillColor;
}

void SolidShape::SetFillColor(const ColorType color)
{
	m_fillColor = color;
}
