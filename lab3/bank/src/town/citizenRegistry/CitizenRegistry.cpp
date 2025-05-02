//
// Created by smmm on 29.04.2025.
//

#include "CitizenRegistry.h"

CitizenRegistry::CitizenRegistry(Bank bank)
{
	const Money allCash = bank.GetCash();
	const Money share{ allCash / k_citizenCount };
	const Money reminder{ allCash % k_citizenCount };
	CitizenApu apu(bank, this, share);

}

