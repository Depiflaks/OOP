//
// Created by smmm on 06.05.2025.
//

#ifndef ICANVAS_H
#define ICANVAS_H

#include "../point/Point.h"

#include <cstdint>
#include <vector>

using ColorType = uint32_t;

constexpr ColorType k_black = 0xff000000;
constexpr ColorType k_white = 0xffffff;

class ICanvas {
public:
	virtual ~ICanvas() = default;

	virtual void DrawLine(Point from, Point to, ColorType lineColor) = 0;
	virtual void FillPolygon(std::vector<Point> points, ColorType fillColor) = 0;
	virtual void DrawCircle(Point center, double radius, ColorType lineColor) = 0;
	virtual void FillCircle(Point center, double radius, ColorType fillColor) = 0;
};


#endif //ICANVAS_H
