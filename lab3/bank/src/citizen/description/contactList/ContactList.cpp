//
// Created by smmm on 27.03.2025.
//

#include "ContactList.h"

const CitizenHomer& ContactList::GetHomer()
{
	CheckContactExist(m_homer, CitizenName::homerSimpson);
	return *m_homer;
}

const CitizenMarge& ContactList::GetMarge()
{
	CheckContactExist(m_marge, CitizenName::margeSimpson);
	return *m_marge;
}

const CitizenBartAndLisa& ContactList::GetBartAndLisa()
{
	CheckContactExist(m_bartAndLisa, CitizenName::bartAndLisaSimpson);
	return *m_bartAndLisa;
}

const CitizenApu& ContactList::GetApu()
{
	CheckContactExist(m_apu, CitizenName::apu);
	return *m_apu;
}

const CitizenMrBurns& ContactList::GetMrBurns()
{
	CheckContactExist(m_mrBurns, CitizenName::mrBurns);
	return *m_mrBurns;
}

const CitizenNelson& ContactList::GetNelson()
{
	CheckContactExist(m_nelson, CitizenName::nelson);
	return *m_nelson;
}

const CitizenSnake& ContactList::GetSnake()
{
	CheckContactExist(m_snake, CitizenName::snake);
	return *m_snake;
}

const CitizenSmithers& ContactList::GetSmithers()
{
	CheckContactExist(m_smithers, CitizenName::waylonSmithers);
	return *m_smithers;
}

void ContactList::SetHomer(CitizenHomer& citizen)
{
	m_homer.emplace(citizen);
}

void ContactList::SetMarge(CitizenMarge& citizen)
{
	m_marge.emplace(citizen);
}

void ContactList::SetBartAndLisa(CitizenBartAndLisa& citizen)
{
	m_bartAndLisa.emplace(citizen);
}

void ContactList::SetApu(CitizenApu& citizen)
{
	m_apu.emplace(citizen);
}

void ContactList::SetMrBurns(CitizenMrBurns& citizen)
{
	m_mrBurns.emplace(citizen);
}

void ContactList::SetNelson(CitizenNelson& citizen)
{
	m_nelson.emplace(citizen);
}

void ContactList::SetSnake(CitizenSnake& citizen)
{
	m_snake.emplace(citizen);
}

void ContactList::SetSmithers(CitizenSmithers& citizen)
{
	m_smithers.emplace(citizen);
}

void ContactList::CheckContactExist(const std::optional<Citizen&> citizen, const CitizenName name)
{
	if (!citizen.has_value())
		throw ContactNotFoundException(name);
}
