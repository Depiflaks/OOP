//
// Created by smmm on 06.05.2025.
//

#ifndef SHAPE_H
#define SHAPE_H
#include "canvas/ICanvas.h"
#include "drawable/ICanvasDrawable.h"

#include <string>

enum class ShapeType
{
	triangle,
	rectangle,
	circle,
	lineSegment,
};

class Shape : public ICanvasDrawable
{
public:
	explicit Shape();
	explicit Shape(Color outlineColor);

	[[nodiscard]] virtual double GetArea() const = 0;
	[[nodiscard]] virtual double GetPerimeter() const = 0;
	[[nodiscard]] virtual std::string ToString() const = 0;

	[[nodiscard]] Color GetOutlineColor() const;
	void SetOutlineColor(Color color);

private:
	Color m_outlineColor;
};

#endif // SHAPE_H
