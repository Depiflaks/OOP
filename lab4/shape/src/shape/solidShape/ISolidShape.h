//
// Created by smmm on 06.05.2025.
//

#ifndef ISOLIDSHAPE_H
#define ISOLIDSHAPE_H
#include "Canvas/ICanvas.h"
#include "shape/IShape.h"

class ISolidShape : IShape
{
public:
	virtual ColorType GetFillColor() = 0;
};

#endif // ISOLIDSHAPE_H
