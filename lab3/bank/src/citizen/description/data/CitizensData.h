//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZENSDATA_H
#define CITIZENSDATA_H

#include "../../citizens/apu/CitizenApu.h"
#include "../../citizens/bartAndLisa/CitizenBartAndLisa.h"
#include "../../citizens/homer/CitizenHomer.h"
#include "../../citizens/marge/CitizenMarge.h"
#include "../../citizens/mrBurns/CitizenMrBurns.h"
#include "../../citizens/nelson/CitizenNelson.h"
#include "../../citizens/smithers/CitizenSmithers.h"
#include "../../citizens/snake/CitizenSnake.h"

class CitizensData
{
public:
	explicit CitizensData(Bank& bank, Money amount);

	CitizenHomer m_homer;
	CitizenMarge m_marge;
	CitizenBartAndLisa m_bartAndLisa;
	CitizenApu m_apu;
	CitizenMrBurns m_mrBurns;
	CitizenNelson m_nelson;
	CitizenSnake m_snake;
	CitizenSmithers m_smithers;

private:
	const size_t k_citizensCount{ 8 };
};

#endif // CITIZENSDATA_H
