//
// Created by smmm on 15.05.2025.
//

#include "MyString.h"

#include <cstring>

char* k_emptyString = { '\0' };

MyString::MyString()
{
	m_data = k_emptyString;
}

MyString::MyString(const char* pString)
{
	InitFromBuffer(pString, strlen(pString));
}

MyString::MyString(const char* pString, const size_t length)
{
	InitFromBuffer(pString, length);
}

MyString::MyString(MyString const& other)
{
	InitFromBuffer(other.m_data, other.m_length);
}

MyString::MyString(MyString&& other) noexcept
	: m_data(other.m_data)
	, m_length(other.m_length)
	, m_capacity(other.m_capacity)
{
	other.m_data = k_emptyString;
	other.m_length = 0;
	other.m_capacity = 0;
}

MyString::MyString(std::string const& stlString)
{
	InitFromBuffer(stlString.c_str(), stlString.length());
}

MyString::~MyString()
{
	delete[] m_data;
}

size_t MyString::GetLength() const
{
	return m_length;
}

const char* MyString::GetStringData() const
{
	return m_data;
}

MyString MyString::SubString(const size_t start, const size_t length) const
{
	return MyString{ m_data + start, std::min(m_length - start, length) };
}

void MyString::Clear()
{
	delete[] m_data;
	m_length = 0;
	m_capacity = 0;
	m_data = k_emptyString;
}

size_t MyString::GetCapacity() const
{
	return m_capacity;
}

void MyString::InitFromBuffer(const char* pString, const size_t length)
{
	if (pString == nullptr)
		return;
	m_length = length;
	m_capacity = m_length;
	m_data = new char[m_capacity + 1];
	m_data[m_length] = *k_emptyString;
	std::memcpy(m_data, pString, m_length);
}
