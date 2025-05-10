//
// Created by smmm on 06.05.2025.
//

#ifndef SOLID_SHAPE_H
#define SOLID_SHAPE_H
#include "Canvas/ICanvas.h"
#include "shape/IShape.h"

class SolidShape : IShape
{
public:
	explicit SolidShape(ColorType fillColor);
	[[nodiscard]] ColorType GetFillColor() const;
	void SetFillColor(ColorType color);

private:
	ColorType m_fillColor;
};

#endif // SOLID_SHAPE_H
