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

	// конструктор, инициализирующий строку данными строки
	// с завершающим нулевым символом
	explicit MyString(const char* pString);
	void InitFromBuffer(const char* pString, size_t length);

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
	explicit MyString(std::string const& stlString);

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
	size_t GetCapacity() const;

private:
	char* m_data{nullptr};
	size_t m_length{ 0 };
	size_t m_capacity{ 0 };

	void Resize(size_t newCapacity);
};

#endif // MYSTRING_H
