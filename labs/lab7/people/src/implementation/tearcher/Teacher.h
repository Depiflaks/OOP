//
// Created by smmm on 29.05.2025.
//

#ifndef TEACHER_H
#define TEACHER_H
#include <utility>

#include "implementation/PersonImpl.h"

class Teacher final : public PersonImpl<ITeacher>
{
public:
	Teacher(const std::string& first, const std::string& last,
		const std::string& patronymic, const std::string& address,
		std::string subject)
		: PersonImpl(first, last, patronymic, address)
		, m_subject(std::move(subject))
	{
	}

	[[nodiscard]] std::string GetSubject() const override { return m_subject; }
	void SetSubject(const std::string& val) override { m_subject = val; }

private:
	std::string m_subject;
};

#endif // TEACHER_H
