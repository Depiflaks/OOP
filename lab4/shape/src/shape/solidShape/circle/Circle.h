//
// Created by smmm on 10.05.2025.
//

#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape/solidShape/SolidShape.h"

class Circle final : SolidShape
{
public:
	double GetArea() override;
	double GetPerimeter() override;
	std::string ToString() override;

	void Draw(ICanvas& canvas) override;

	[[nodiscard]] Point GetCenter() const;
	[[nodiscard]] double GetRadius() const;

private:
	Point m_center{};
	double m_radius{};
};

#endif // CIRCLE_H
