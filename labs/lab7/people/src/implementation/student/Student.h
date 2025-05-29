//
// Created by smmm on 29.05.2025.
//

#ifndef STUDENT_H
#define STUDENT_H
#include "implementation/StudentImpl.h"
#include "interface/student/IStudent.h"

class Student final : public StudentImpl<IStudent>
{
public:
	Student(const std::string& first, const std::string& last,
		const std::string& patronymic, const std::string& address,
		const std::string& university, const std::string& studentId)
		: StudentImpl(first, last, patronymic, address, university, studentId)
	{
	}
};

#endif // STUDENT_H
