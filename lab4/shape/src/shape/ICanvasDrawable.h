//
// Created by smmm on 06.05.2025.
//

#ifndef ICANVASDRAWABLE_H
#define ICANVASDRAWABLE_H
#include "Canvas/ICanvas.h"

class ICanvasDrawable
{
public:
	virtual ~ICanvasDrawable() = default;
	virtual void Draw(ICanvas& canvas) = 0;
};

#endif // ICANVASDRAWABLE_H
