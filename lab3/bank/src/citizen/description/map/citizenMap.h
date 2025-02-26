//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZEN_MAP_H
#define CITIZEN_MAP_H
#include "../../ICitizen.h"
#include "../name/CitizenName.h"

#include <map>
#include <memory>
using CitizenMap = std::map<CitizenName, std::unique_ptr<ICitizen>>;

#endif // CITIZEN_MAP_H
