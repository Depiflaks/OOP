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
	Rectangle(Point leftTop, double width, double height);
	Rectangle(Point leftTop, double width, double height, Color outlineColor);
	Rectangle(Point leftTop, double width, double height, Color outlineColor, Color fillColor);

	double GetArea() override;
	double GetPerimeter() override;
	std::string ToString() override;

	void Draw(ICanvas& canvas) override;

	friend std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle);
    friend std::istream& operator>>(std::istream& is, Rectangle& rectangle);

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
