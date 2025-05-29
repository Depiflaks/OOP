//
// Created by smmm on 29.05.2025.
//

#ifndef STUDENTIMPL_H
#define STUDENTIMPL_H
#include <utility>

#include "PersonImpl.h"
#include "interface/student/IStudent.h"

template <typename Base>
concept DerivedFromIStudent = std::is_base_of_v<IStudent, Base>;

template <DerivedFromIStudent Base>
class StudentImpl : public PersonImpl<Base>
{
public:
	StudentImpl(const std::string& first, const std::string& last,
		const std::string& patronymic, const std::string& address,
		std::string university, std::string studentId)
		: PersonImpl<Base>(first, last, patronymic, address)
		, m_university(std::move(university))
		, m_studentId(std::move(studentId))
	{
	}

	[[nodiscard]] std::string GetUniversity() const override { return m_university; }
	void SetUniversity(const std::string& val) override { m_university = val; }
	[[nodiscard]] std::string GetStudentId() const override { return m_studentId; }
	void SetStudentId(const std::string& val) override { m_studentId = val; }

private:
	std::string m_university;
	std::string m_studentId;
};

#endif // STUDENTIMPL_H
