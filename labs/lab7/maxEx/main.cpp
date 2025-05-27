//
// Created by smmm on 27.05.2025.
//

#include "athlete/Athlete.h"
#include "findMax.h"

#include <iostream>
#include <vector>
int main()
{
	std::vector<Athlete> athletes = {
		{ "Иван Иванов", 1.80, 75.0 },
		{ "Петр Петров", 1.90, 85.5 },
		{ "Сидр Сидоров", 1.85, 90.0 }
	};

	Athlete maxHeightAthlete = athletes[0];
	if (FindMax(athletes, maxHeightAthlete, CompareByHeight))
		std::cout << "Спортсмен с максимальным ростом: " << maxHeightAthlete << "\n";

	Athlete maxWeightAthlete = athletes[0];
	if (FindMax(athletes, maxWeightAthlete, CompareByWeight))
		std::cout << "Спортсмен с максимальным весом: " << maxWeightAthlete << "\n";

	return 0;
}