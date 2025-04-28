//
// Created by smmm on 27.03.2025.
//

#include "ContactList.h"
ContactList::ContactList(Bank& bank, const Money amount)
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

const CitizenHomer& ContactList::getHomer()
{
	return m_homer;
}

const CitizenMarge& ContactList::getMarge()
{
	return m_marge;
}

const CitizenBartAndLisa& ContactList::getBartAndLisa()
{
	return m_bartAndLisa;
}

const CitizenApu& ContactList::getApu()
{
	return m_apu;
}

const CitizenMrBurns& ContactList::getMrBurns()
{
	return m_mrBurns;
}

const CitizenNelson& ContactList::getNelson()
{
	return m_nelson;
}

const CitizenSnake& ContactList::getSnake()
{
	return m_snake;
}

const CitizenSmithers& ContactList::getSmithers()
{
	return m_smithers;
}
