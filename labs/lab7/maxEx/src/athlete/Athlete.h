//
// Created by smmm on 27.05.2025.
//

#ifndef ATHLETE_H
#define ATHLETE_H
#include <string>
#include <iostream>

struct Athlete
{
	Athlete(std::string name, double height, double weight);

	std::string name;
	double height;
	double weight;
};

inline std::ostream& operator<<(std::ostream& os, Athlete const& a)
{
    os << a.name << " (рост: " << a.height << ", вес: " << a.weight << ")";
    return os;
}

inline bool CompareByHeight(const Athlete& a, const Athlete& b) { return a.height < b.height; }

inline bool CompareByWeight(const Athlete& a, const Athlete& b) { return a.weight < b.weight; }

#endif // ATHLETE_H
