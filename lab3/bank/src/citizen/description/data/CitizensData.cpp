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