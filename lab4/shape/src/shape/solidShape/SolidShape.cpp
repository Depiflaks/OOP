//
// Created by smmm on 06.05.2025.
//

#include "SolidShape.h"

SolidShape::SolidShape(const ColorType fillColor)
	: m_fillColor(fillColor)
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

