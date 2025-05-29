//
// Created by smmm on 29.05.2025.
//

#ifndef WORKER_H
#define WORKER_H
#include <utility>

#include "implementation/PersonImpl.h"

class Worker final : public PersonImpl<IWorker>
{
public:
	Worker(const std::string& first, const std::string& last,
		const std::string& patronymic, const std::string& address,
		std::string specialty)
		: PersonImpl(first, last, patronymic, address)
		, m_specialty(std::move(specialty))
	{
	}

	[[nodiscard]] std::string GetSpecialty() const override { return m_specialty; }
	void SetSpecialty(const std::string& val) override { m_specialty = val; }

private:
	std::string m_specialty;
};

#endif // WORKER_H
