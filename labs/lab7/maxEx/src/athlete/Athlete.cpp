//
// Created by smmm on 27.05.2025.
//

#include "Athlete.h"

Athlete::Athlete(std::string name, const double height, const double weight)
	: name(std::move(name))
	, height(height)
	, weight(weight)
{
}