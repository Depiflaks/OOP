//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZENS_REGISTRY_H
#define CITIZENS_REGISTRY_H

#include "../../citizens/apu/CitizenApu.h"
#include "../../citizens/bartAndLisa/CitizenBartAndLisa.h"
#include "../../citizens/homer/CitizenHomer.h"
#include "../../citizens/marge/CitizenMarge.h"
#include "../../citizens/mrBurns/CitizenMrBurns.h"
#include "../../citizens/nelson/CitizenNelson.h"
#include "../../citizens/smithers/CitizenSmithers.h"
#include "../../citizens/snake/CitizenSnake.h"

class ContactNotFoundException final : public std::runtime_error
{
public:
	explicit ContactNotFoundException(Citizen &citizen)
		: std::runtime_error{ "Contact" }
	{
	}
	~ContactNotFoundException() override = default;
};

class ContactList
{
public:
	explicit ContactList(Bank& bank, Money amount);

	const CitizenHomer& getHomer();
	const CitizenMarge& getMarge();
	const CitizenBartAndLisa& getBartAndLisa();
	const CitizenApu& getApu();
	const CitizenMrBurns& getMrBurns();
	const CitizenNelson& getNelson();
	const CitizenSnake& getSnake();
	const CitizenSmithers& getSmithers();

private:
	std::optional<CitizenHomer&> m_homer;
	std::optional<CitizenMarge&> m_marge;
	std::optional<CitizenBartAndLisa&> m_bartAndLisa;
	std::optional<CitizenApu&> m_apu;
	std::optional<CitizenMrBurns&> m_mrBurns;
	std::optional<CitizenNelson&> m_nelson;
	std::optional<CitizenSnake&> m_snake;
	std::optional<CitizenSmithers&> m_smithers;

	const size_t k_citizensCount{ 8 };
};

#endif // CITIZENS_REGISTRY_H
