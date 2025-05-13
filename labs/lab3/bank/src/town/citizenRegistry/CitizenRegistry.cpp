//
// Created by smmm on 29.04.2025.
//

#include "CitizenRegistry.h"

#include "../../random/random.h"
#include "citizens.h"

CitizenRegistry::CitizenRegistry(Bank& bank)
{
	const Money allCash = bank.GetCash();
	const Money share{ allCash / k_citizenCount };
	const Money reminder{ allCash % k_citizenCount };

	m_citizens[CitizenName::apu] = std::make_unique<CitizenApu>(bank, *this, share);
	m_citizens[CitizenName::homerSimpson] = std::make_unique<CitizenHomer>(bank, *this, share);
	m_citizens[CitizenName::margeSimpson] = std::make_unique<CitizenMarge>(bank, *this, share);
	m_citizens[CitizenName::bartSimpson] = std::make_unique<CitizenBart>(bank, *this, share);
	m_citizens[CitizenName::lisaSimpson] = std::make_unique<CitizenLisa>(bank, *this, share);
	m_citizens[CitizenName::waylonSmithers] = std::make_unique<CitizenSmithers>(bank, *this, share);
	m_citizens[CitizenName::nelson] = std::make_unique<CitizenNelson>(bank, *this, share);
	m_citizens[CitizenName::snake] = std::make_unique<CitizenSnake>(bank, *this, share);
	m_citizens[CitizenName::mrBurns] = std::make_unique<CitizenMrBurns>(bank, *this, share + reminder);
}

Citizen& CitizenRegistry::GetCitizen(const CitizenName name)
{
	CheckCitizenExist(name);
	return *m_citizens.at(name);
}

Citizen& CitizenRegistry::GetRandomCitizen()
{
	auto it = m_citizens.begin();
	const int citizenIndex = GetRandomNumber(0, static_cast<int>(m_citizens.size()) - 1);
	std::advance(it, citizenIndex);
	return *it->second;
}

std::map<CitizenName, std::unique_ptr<Citizen>>& CitizenRegistry::GetCitizens()
{
	return m_citizens;
}

void CitizenRegistry::CheckCitizenExist(const CitizenName name) const
{
	if (!m_citizens.contains(name))
		throw ContactNotFoundException(name);
}
