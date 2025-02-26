//
// Created by smmm on 19.03.2025.
//

#ifndef CHARACTER_H
#define CHARACTER_H
#include <stdexcept>
#include <string>

class CitizenNameException final : public std::runtime_error
{
public:
	using runtime_error::runtime_error;
	~CitizenNameException() override = default;
};

enum class CitizenName
{
	homerSimpson,
	margeSimpson,
	bartSimpson,
	lisaSimpson,
	apu,
	mrBurns,
	nelson,
	snake,
	waylonSmithers
};

inline std::string getName(const CitizenName name)
{
	switch (name)
	{
	case CitizenName::homerSimpson:
		return "Homer Simpson";
	case CitizenName::margeSimpson:
		return "Marge Simpson";
	case CitizenName::bartSimpson:
		return "Bart Simpson";
	case CitizenName::lisaSimpson:
		return "Lisa Simpson";
	case CitizenName::apu:
		return "Apu";
	case CitizenName::mrBurns:
		return "Mr. Burns";
	case CitizenName::nelson:
		return "Nelson";
	case CitizenName::snake:
		return "Criminal Snake";
	case CitizenName::waylonSmithers:
		return "Waylon Smithers";
	}
	throw CitizenNameException{ "Invalid name" };
}

#endif // CHARACTER_H
