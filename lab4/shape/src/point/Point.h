//
// Created by smmm on 06.05.2025.
//

#ifndef POINT_H
#define POINT_H
#include <cmath>

struct Point
{
	double x;
	double y;

	static double Distance(const Point& a, const Point& b)
	{
		return std::hypot(a.x - b.x, a.y - b.y);
	}
};

#endif // POINT_H
