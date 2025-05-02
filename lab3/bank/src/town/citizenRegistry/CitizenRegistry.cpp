//
// Created by smmm on 29.04.2025.
//

#include "CitizenRegistry.h"

#include "../../citizen/citizens/apu/CitizenApu.h"
#include "../../random/random.h"

CitizenRegistry::CitizenRegistry(Bank bank)
{
	const Money allCash = bank.GetCash();
	const Money share{ allCash / k_citizenCount };
	const Money reminder{ allCash % k_citizenCount };

	m_citizens[CitizenName::apu] = std::make_unique<CitizenApu>(bank, *this, share);
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

void CitizenRegistry::CheckCitizenExist(const CitizenName name) const
{
	if (m_citizens.contains(name))
		throw ContactNotFoundException(name);
}
