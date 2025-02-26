//
// Created by smmm on 27.03.2025.
//

#include "CitizensRegistry.h"
CitizensRegistry::CitizensRegistry(Bank& bank, const Money amount)
	: m_homer{ bank, *this, amount / k_citizensCount }
	, m_marge{ bank, *this, amount / k_citizensCount }
	, m_bartAndLisa{ bank, *this, amount / k_citizensCount }
	, m_apu{ bank, *this, amount / k_citizensCount }
	, m_mrBurns{ bank, *this, amount / k_citizensCount }
	, m_nelson{ bank, *this, amount / k_citizensCount }
	, m_snake{ bank, *this, amount / k_citizensCount }
	, m_smithers{ bank, *this, amount / k_citizensCount }
{
}

const CitizenHomer& CitizensRegistry::getHomer()
{
	return m_homer;
}

const CitizenMarge& CitizensRegistry::getMarge()
{
	return m_marge;
}

const CitizenBartAndLisa& CitizensRegistry::getBartAndLisa()
{
	return m_bartAndLisa;
}

const CitizenApu& CitizensRegistry::getApu()
{
	return m_apu;
}

const CitizenMrBurns& CitizensRegistry::getMrBurns()
{
	return m_mrBurns;
}

const CitizenNelson& CitizensRegistry::getNelson()
{
	return m_nelson;
}

const CitizenSnake& CitizensRegistry::getSnake()
{
	return m_snake;
}

const CitizenSmithers& CitizensRegistry::getSmithers()
{
	return m_smithers;
}
