//
// Created by smmm on 06.05.2025.
//

#include "Shape.h"

Shape::Shape(const ColorType outlineColor)
	: m_outlineColor(outlineColor)
{
}

ColorType Shape::GetOutlineColor() const
{
	return m_outlineColor;
}

void Shape::SetOutlineColor(const ColorType color)
{
	m_outlineColor = color;
}