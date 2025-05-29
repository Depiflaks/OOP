//
// Created by smmm on 29.05.2025.
//

#ifndef ADVANCEDSTUDENT_H
#define ADVANCEDSTUDENT_H
#include <utility>

#include "implementation/StudentImpl.h"
#include "interface/student/IStudent.h"

class AdvancedStudent final : public StudentImpl<IAdvancedStudent>
{
public:
	AdvancedStudent(const std::string& first, const std::string& last,
		const std::string& patronymic, const std::string& address,
		const std::string& university, const std::string& studentId,
		std::string dissertationTopic)
		: StudentImpl(first, last, patronymic, address, university, studentId)
		, m_dissertationTopic(std::move(dissertationTopic))
	{
	}

	[[nodiscard]] std::string GetDissertationTopic() const override { return m_dissertationTopic; }
	void SetDissertationTopic(const std::string& val) override { m_dissertationTopic = val; }

private:
	std::string m_dissertationTopic;
};

#endif // ADVANCEDSTUDENT_H
