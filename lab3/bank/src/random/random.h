//
// Created by smmm on 29.04.2025.
//

#ifndef RANDOM_H
#define RANDOM_H

#include "../bank/Bank.h"
#include <random>

static constexpr Money k_minExpenseAmount{ 1 };
static constexpr Money k_maxExpenseAmount{ 1 };

int GetRandomNumber(int min, int max);
inline Money GetRandomExpenseAmount();
// todo: вынести в town.h

#endif // RANDOM_H
