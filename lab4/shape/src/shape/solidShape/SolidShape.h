//
// Created by smmm on 06.05.2025.
//

#ifndef SOLID_SHAPE_H
#define SOLID_SHAPE_H
#include "canvas/ICanvas.h"
#include "shape/Shape.h"

class SolidShape : Shape
{
public:
	explicit SolidShape(ColorType outlineColor, ColorType fillColor);
	explicit SolidShape(ColorType outlineColor);
	explicit SolidShape();

	[[nodiscard]] ColorType GetFillColor() const;
	void SetFillColor(ColorType color);

private:
	ColorType m_fillColor;
};

#endif // SOLID_SHAPE_H
