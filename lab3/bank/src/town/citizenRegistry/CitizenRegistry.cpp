//
// Created by smmm on 29.04.2025.
//

#include "CitizenRegistry.h"

#include "../../citizen/citizens/apu/CitizenApu.h"

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

}

Citizen& CitizenRegistry::GetRandomCitizen()
{
}

void CitizenRegistry::CheckCitizenExist(const CitizenName name) const
{
	if (m_citizens.contains(name))
		throw ContactNotFoundException(name);
}

