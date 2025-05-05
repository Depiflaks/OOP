//
// Created by smmm on 05.05.2025.
//

#ifndef ICITIZEN_H
#define ICITIZEN_H
#include "../description/name/CitizenName.h"

class ICitizen
{
public:
	virtual ~ICitizen() = default;
	virtual void PerformRandomActionWithErrorHandling() = 0;
	virtual CitizenName GetName() = 0;

private:
	explicit ICitizen() = default;
};

#endif // ICITIZEN_H
