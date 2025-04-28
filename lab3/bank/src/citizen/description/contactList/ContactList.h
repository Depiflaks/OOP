//
// Created by smmm on 27.03.2025.
//

#ifndef CITIZENS_REGISTRY_H
#define CITIZENS_REGISTRY_H

#include "../../citizens/apu/CitizenApu.h"
#include "../../citizens/bartAndLisa/CitizenBartAndLisa.h"
#include "../../citizens/homer/CitizenHomer.h"
#include "../../citizens/marge/CitizenMarge.h"
#include "../../citizens/mrBurns/CitizenMrBurns.h"
#include "../../citizens/nelson/CitizenNelson.h"
#include "../../citizens/smithers/CitizenSmithers.h"
#include "../../citizens/snake/CitizenSnake.h"

class ContactNotFoundException final : public std::runtime_error
{
public:
	explicit ContactNotFoundException(const CitizenName name)
		: std::runtime_error{ "Contact of citizen: " + GetName(name) + " not found" }
	{
	}
	~ContactNotFoundException() override = default;
};

class ContactList
{
public:
	explicit ContactList() = default;
	~ContactList() = default;

	const CitizenHomer& GetHomer();
	const CitizenMarge& GetMarge();
	const CitizenBartAndLisa& GetBartAndLisa();
	const CitizenApu& GetApu();
	const CitizenMrBurns& GetMrBurns();
	const CitizenNelson& GetNelson();
	const CitizenSnake& GetSnake();
	const CitizenSmithers& GetSmithers();
	Citizen& GetRandomCitizen();

protected:
	void SetHomer(CitizenHomer& citizen);
	void SetMarge(CitizenMarge& citizen);
	void SetBartAndLisa(CitizenBartAndLisa& citizen);
	void SetApu(CitizenApu& citizen);
	void SetMrBurns(CitizenMrBurns& citizen);
	void SetNelson(CitizenNelson& citizen);
	void SetSnake(CitizenSnake& citizen);
	void SetSmithers(CitizenSmithers& citizen);

private:
	std::optional<CitizenHomer&> m_homer;
	std::optional<CitizenMarge&> m_marge;
	std::optional<CitizenBartAndLisa&> m_bartAndLisa;
	std::optional<CitizenApu&> m_apu;
	std::optional<CitizenMrBurns&> m_mrBurns;
	std::optional<CitizenNelson&> m_nelson;
	std::optional<CitizenSnake&> m_snake;
	std::optional<CitizenSmithers&> m_smithers;

	std::vector<std::optional<Citizen&>> m_citizens{
		m_homer,
		m_marge,
		m_bartAndLisa,
		m_apu,
		m_mrBurns,
		m_nelson,
		m_snake,
		m_smithers
	};

	static static void CheckContactExist(std::optional<Citizen&> citizen, CitizenName name);
};

#endif // CITIZENS_REGISTRY_H
