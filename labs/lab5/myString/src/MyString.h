//
// Created by smmm on 15.05.2025.
//

#ifndef MYSTRING_H
#define MYSTRING_H

#include "iterator/MyStringIterator.h"

#include <cstdint>
#include <istream>
#include <ostream>
#include <string>

class MyString
{
public:
	using iterator = MyStringIterator<char>;
	using const_iterator = MyStringIterator<const char>;
	using reverse_iterator = std::reverse_iterator<iterator>;
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	// конструктор по умолчанию
	MyString();

	MyString(char ch);

	// конструктор, инициализирующий строку данными строки
	// с завершающим нулевым символом
	MyString(const char* pString);

	// конструктор, инициализирующий строку данными из
	// символьного массива заданной длины
	MyString(const char* pString, size_t length);

	// конструктор копирования
	MyString(MyString const& other);

	// перемещающий конструктор
	//  реализуется совместно с перемещающим оператором присваивания
	MyString(MyString&& other) noexcept;

	// конструктор, инициализирующий строку данными из
	// строки стандартной библиотеки C++
	MyString(std::string const& stlString);

	// деструктор класса - освобождает память, занимаемую символами строки
	~MyString();

	// возвращает длину строки (без учета завершающего нулевого символа)
	[[nodiscard]] size_t GetLength() const;

	// возвращает указатель на массив символов строки.
	// В конце массива обязательно должен быть завершающий нулевой символ
	// даже если строка пустая
	[[nodiscard]] const char* GetStringData() const;

	// возвращает подстроку с заданной позиции длиной не больше length символов
	[[nodiscard]] MyString SubString(size_t start, size_t length = SIZE_MAX) const;

	// очистка строки (строка становится снова нулевой длины)
	void Clear();

	// Возвращает вместимость строки
	[[nodiscard]] size_t GetCapacity() const;

	MyString& operator=(const MyString& other);

	MyString& operator=(MyString&& other) noexcept;

	char& operator[](size_t index) const;

	MyString& operator+=(const MyString& other);

	iterator begin() { return { m_data, m_data, m_data + m_length }; }
	iterator end() { return { m_data + m_length, m_data, m_data + m_length }; }

	[[nodiscard]] const_iterator begin() const { return { m_data, m_data, m_data + m_length }; }
	[[nodiscard]] const_iterator end() const { return { m_data + m_length, m_data, m_data + m_length }; }

	[[nodiscard]] const_iterator cbegin() const { return begin(); }
	[[nodiscard]] const_iterator cend() const { return end(); }

	reverse_iterator rbegin() { return reverse_iterator(end()); }
	reverse_iterator rend() { return reverse_iterator(begin()); }

	[[nodiscard]] const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
	[[nodiscard]] const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

	[[nodiscard]] const_reverse_iterator crbegin() const { return const_reverse_iterator(cend()); }
	[[nodiscard]] const_reverse_iterator crend() const { return const_reverse_iterator(cbegin()); }

private:
	char* m_data{ nullptr };
	size_t m_length{ 0 };
	size_t m_capacity{ 0 };

	void InitFromBuffer(const char* pString, size_t length);
	void DeleteData() const;
	void MoveFrom(const MyString& other);
	static void MakeEmpty(MyString& other);
};

inline std::strong_ordering operator<=>(const MyString& lhs, const MyString& rhs)
{
	const size_t minLength = std::min(lhs.GetLength(), rhs.GetLength());

	for (size_t i = 0; i < minLength; ++i)
	{
		if (lhs[i] < rhs[i])
			return std::strong_ordering::less;
		if (lhs[i] > rhs[i])
			return std::strong_ordering::greater;
	}

	if (lhs.GetLength() < rhs.GetLength())
		return std::strong_ordering::less;
	if (lhs.GetLength() > rhs.GetLength())
		return std::strong_ordering::greater;

	return std::strong_ordering::equal;
}

inline bool operator==(const MyString& lhs, const MyString& rhs)
{
	if (lhs.GetLength() != rhs.GetLength())
		return false;
	for (size_t i = 0; i < lhs.GetLength(); ++i)
		if (lhs[i] != rhs[i])
			return false;
	return true;
}

inline MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString result(lhs);
	result += rhs;
	return result;
}

inline std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	const char* data = str.GetStringData();
	return os.write(data, static_cast<std::streamsize>(str.GetLength()));
}

inline std::istream& operator>>(std::istream& is, MyString& str)
{
	str.Clear();
	char ch;
	while (is.get(ch) && !std::isspace(static_cast<unsigned char>(ch)))
		str += ch;
	return is;
}

#endif // MYSTRING_H
