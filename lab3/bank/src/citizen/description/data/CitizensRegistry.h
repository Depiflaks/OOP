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

class CitizensRegistry
{
public:
	explicit CitizensRegistry(Bank& bank, Money amount);

	const CitizenHomer& getHomer();
	const CitizenMarge& getMarge();
	const CitizenBartAndLisa& getBartAndLisa();
	const CitizenApu& getApu();
	const CitizenMrBurns& getMrBurns();
	const CitizenNelson& getNelson();
	const CitizenSnake& getSnake();
	const CitizenSmithers& getSmithers();

private:
	CitizenHomer m_homer;
	CitizenMarge m_marge;
	CitizenBartAndLisa m_bartAndLisa;
	CitizenApu m_apu;
	CitizenMrBurns m_mrBurns;
	CitizenNelson m_nelson;
	CitizenSnake m_snake;
	CitizenSmithers m_smithers;

	const size_t k_citizensCount{ 8 };
};

#endif // CITIZENS_REGISTRY_H
