//
// Created by smmm on 06.05.2025.
//

#ifndef ISHAPE_H
#define ISHAPE_H
#include "Canvas/ICanvas.h"
#include "drawable/ICanvasDrawable.h"

#include <string>

class IShape : public ICanvasDrawable
{
public:
	virtual double GetArea() = 0;
	virtual double GetPerimeter() = 0;
	virtual std::string ToString() = 0;
	virtual ColorType GetOutlineColor() = 0;
};

#endif // ISHAPE_H
