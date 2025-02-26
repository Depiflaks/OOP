//
// Created by smmm on 27.03.2025.
//

#include "CitizensData.h"
CitizensData::CitizensData(Bank& bank, const Money amount)
	: m_homer(bank, *this, amount / k_citizensCount)
	, m_marge(bank, *this, amount / k_citizensCount)
	, m_bartAndLisa(bank, *this, amount / k_citizensCount)
	, m_apu(bank, *this, amount / k_citizensCount)
	, m_mrBurns(bank, *this, amount / k_citizensCount)
	, m_nelson(bank, *this, amount / k_citizensCount)
	, m_snake(bank, *this, amount / k_citizensCount)
	, m_smithers(bank, *this, amount / k_citizensCount + amount % k_citizensCount)
{
}

const CitizenHomer& CitizensData::getHomer()
{
	return m_homer;
}

const CitizenMarge& CitizensData::getMarge()
{
	return m_marge;
}

const CitizenBartAndLisa& CitizensData::getBartAndLisa()
{
	return m_bartAndLisa;
}

const CitizenApu& CitizensData::getApu()
{
	return m_apu;
}

const CitizenMrBurns& CitizensData::getMrBurns()
{
	return m_mrBurns;
}

const CitizenNelson& CitizensData::getNelson()
{
	return m_nelson;
}

const CitizenSnake& CitizensData::getSnake()
{
	return m_snake;
}

const CitizenSmithers& CitizensData::getSmithers()
{
	return m_smithers;
}
