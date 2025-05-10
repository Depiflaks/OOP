//
// Created by smmm on 06.05.2025.
//

#ifndef SHAPE_H
#define SHAPE_H
#include "canvas/ICanvas.h"
#include "drawable/ICanvasDrawable.h"

#include <string>

class Shape : public ICanvasDrawable
{
public:
	explicit Shape(ColorType outlineColor);

	virtual double GetArea() = 0;
	virtual double GetPerimeter() = 0;
	virtual std::string ToString() = 0;

	[[nodiscard]] ColorType GetOutlineColor() const;
	void SetOutlineColor(ColorType color);

private:
	ColorType m_outlineColor;
};

#endif // SHAPE_H
