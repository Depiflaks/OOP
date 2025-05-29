//
// Created by smmm on 29.05.2025.
//

#ifndef IPERSON_H
#define IPERSON_H

#include <string>

struct IPerson
{
	virtual ~IPerson() = default;
	[[nodiscard]] virtual std::string GetFirstName() const = 0;
	virtual void SetFirstName(const std::string&) = 0;
	[[nodiscard]] virtual std::string GetLastName() const = 0;
	virtual void SetLastName(const std::string&) = 0;
	[[nodiscard]] virtual std::string GetPatronymic() const = 0;
	virtual void SetPatronymic(const std::string&) = 0;
	[[nodiscard]] virtual std::string GetAddress() const = 0;
	virtual void SetAddress(const std::string&) = 0;
};

struct IPupil : public IPerson
{
	[[nodiscard]] virtual std::string GetSchoolName() const = 0;
	virtual void SetSchoolName(const std::string&) = 0;
	[[nodiscard]] virtual std::string GetGrade() const = 0;
	virtual void SetGrade(const std::string&) = 0;
};

struct ITeacher : public IPerson
{
	[[nodiscard]] virtual std::string GetSubject() const = 0;
	virtual void SetSubject(const std::string&) = 0;
};

struct IWorker : public IPerson
{
	[[nodiscard]] virtual std::string GetSpecialty() const = 0;
	virtual void SetSpecialty(const std::string&) = 0;
};

#endif // IPERSON_H
