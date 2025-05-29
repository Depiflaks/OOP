//
// Created by smmm on 29.05.2025.
//

#ifndef PUPIL_H
#define PUPIL_H
#include <utility>

#include "implementation/PersonImpl.h"

class Pupil final : public PersonImpl<IPupil>
{
public:
	Pupil(const std::string& first, const std::string& last,
		const std::string& patronymic, const std::string& address,
		std::string school, std::string grade)
		: PersonImpl(first, last, patronymic, address)
		, m_schoolName(std::move(school))
		, m_grade(std::move(grade))
	{
	}

	[[nodiscard]] std::string GetSchoolName() const override { return m_schoolName; }
	void SetSchoolName(const std::string& val) override { m_schoolName = val; }
	[[nodiscard]] std::string GetGrade() const override { return m_grade; }
	void SetGrade(const std::string& val) override { m_grade = val; }

private:
	std::string m_schoolName;
	std::string m_grade;
};

#endif // PUPIL_H
