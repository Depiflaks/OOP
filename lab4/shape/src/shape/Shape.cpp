//
// Created by smmm on 06.05.2025.
//

#include "Shape.h"

Shape::Shape(const Color outlineColor)
	: m_outlineColor(outlineColor)
{
}

Color Shape::GetOutlineColor() const
{
	return m_outlineColor;
}

void Shape::SetOutlineColor(const Color color)
{
	m_outlineColor = color;
}