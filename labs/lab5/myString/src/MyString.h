//
// Created by smmm on 15.05.2025.
//

#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstdint>
#include <string>

class MyString
{
public:
	// конструктор по умолчанию
	MyString();

	MyString(const char& ch);

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

	char& operator[](size_t index) const;

	MyString& operator+=(const MyString& other);

private:
	char* m_data{ nullptr };
	size_t m_length{ 0 };
	size_t m_capacity{ 0 };

	void InitFromBuffer(const char* pString, size_t length);
};

// inline std::strong_ordering operator<=>(const MyString& lhs, const MyString& rhs)
// {
// 	int cmp = std::strcmp(lhs.GetStringData(), rhs.GetStringData());
// 	if (cmp < 0)
// 		return std::strong_ordering::less;
// 	if (cmp > 0)
// 		return std::strong_ordering::greater;
// 	return std::strong_ordering::equal;
// }
//
// inline bool operator==(const MyString& lhs, const MyString& rhs)
// {
//
// 	return;
// };

inline MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString result(lhs);
	result += rhs;
	return result;
}

#endif // MYSTRING_H
