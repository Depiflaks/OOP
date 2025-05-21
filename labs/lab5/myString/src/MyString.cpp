//
// Created by smmm on 15.05.2025.
//

#include "MyString.h"

#include <cstring>

static char k_stringEnd[] = { '\0' };

MyString::MyString()
{
	m_data = k_stringEnd;
}

MyString::MyString(const char& ch)
	: m_length(1)
	, m_capacity(1)
{
	m_data = new char[2];
	m_data[0] = ch;
	m_data[1] = *k_stringEnd;
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
	other.m_length = 0;
	other.m_capacity = 0;
	other.m_data = k_stringEnd;
}

MyString::MyString(std::string const& stlString)
{
	InitFromBuffer(stlString.c_str(), stlString.length());
}

MyString::~MyString()
{
	if (m_data != k_stringEnd)
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
	if (m_data != k_stringEnd)
		delete[] m_data;
	m_length = 0;
	m_capacity = 0;
	m_data = k_stringEnd;
}

size_t MyString::GetCapacity() const
{
	return m_capacity;
}

char& MyString::operator[](const size_t index) const
{
	return m_data[index];
}

MyString& MyString::operator+=(const MyString& other)
{
	if (m_capacity >= m_length + other.m_length)
		memcpy(m_data + m_length, other.m_data, other.m_length);
	else
	{
		m_capacity = std::max(m_capacity * 2, m_length + other.m_length);
		const auto newData = new char[m_capacity];
		memcpy(newData, m_data, m_length);
		memcpy(newData + m_length, other.m_data, other.m_length);
		delete[] m_data;
		m_data = newData;
	}
	m_length += other.m_length;
	m_data[m_length] = *k_stringEnd;
	return *this;
}

void MyString::InitFromBuffer(const char* pString, const size_t length)
{
	if (pString == nullptr)
		return;
	m_length = length;
	m_capacity = m_length;
	m_data = new char[m_capacity + 1];
	m_data[m_length] = *k_stringEnd;
	std::memcpy(m_data, pString, m_length);
}
