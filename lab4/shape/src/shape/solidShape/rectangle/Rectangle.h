//
// Created by smmm on 06.05.2025.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "canvas/ICanvas.h"
#include "shape/solidShape/SolidShape.h"

#include <string>

class Rectangle final : public SolidShape
{
public:
	double GetArea() override;
	double GetPerimeter() override;
	std::string ToString() override;

	void Draw(ICanvas& canvas) override;

	[[nodiscard]] Point GetLeftTop() const;
	[[nodiscard]] Point GetRightBottom() const;
	[[nodiscard]] double GetWidth() const;
	[[nodiscard]] double GetHeight() const;

private:
	Point m_leftTop{};
	double m_width{};
	double m_height{};
};

#endif // RECTANGLE_H
