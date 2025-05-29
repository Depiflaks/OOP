//
// Created by smmm on 29.05.2025.
//

#ifndef PERSONIMPL_H
#define PERSONIMPL_H

#include "interface/person/IPerson.h"

#include <string>
#include <utility>

template <typename Base>
concept DerivedFromIPerson = std::is_base_of_v<IPerson, Base>;

template <DerivedFromIPerson Base>
class CPersonImpl : public Base
{
public:
	CPersonImpl(std::string first, std::string last,
		std::string patronymic, std::string address)
		: m_firstName(std::move(first))
		, m_lastName(std::move(last))
		, m_patronymic(std::move(patronymic))
		, m_address(std::move(address))
	{
	}

	[[nodiscard]] std::string GetFirstName() const override { return m_firstName; }
	void SetFirstName(const std::string& val) override { m_firstName = val; }
	[[nodiscard]] std::string GetLastName() const override { return m_lastName; }
	void SetLastName(const std::string& val) override { m_lastName = val; }
	[[nodiscard]] std::string GetPatronymic() const override { return m_patronymic; }
	void SetPatronymic(const std::string& val) override { m_patronymic = val; }
	[[nodiscard]] std::string GetAddress() const override { return m_address; }
	void SetAddress(const std::string& val) override { m_address = val; }

private:
	std::string m_firstName;
	std::string m_lastName;
	std::string m_patronymic;
	std::string m_address;
};

#endif // PERSONIMPL_H
