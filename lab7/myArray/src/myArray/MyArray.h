//
// Created by smmm on 13.05.2025.
//

#ifndef MY_ARRAY_H
#define MY_ARRAY_H

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <string>

template <typename T>
class CMyArray
{
public:
	using value_type = T;
	using size_type = std::size_t;
	using iterator = T*;
	using const_iterator = const T*;
	using reverse_iterator = std::reverse_iterator<iterator>;
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	// Конструктор по умолчанию
	CMyArray() noexcept
		: m_data(nullptr)
		, m_size(0)
		, m_capacity(0)
	{
	}

	// Конструктор копирования
	CMyArray(const CMyArray& other)
		: m_data(nullptr)
		, m_size(0)
		, m_capacity(0)
	{
		if (other.m_size > 0)
		{
			reserve(other.m_capacity);
			uninitialized_copy(other.m_data, other.m_data + other.m_size, m_data);
			m_size = other.m_size;
		}
	}

	// Конструктор перемещения
	CMyArray(CMyArray&& other) noexcept
		: m_data(other.m_data)
		, m_size(other.m_size)
		, m_capacity(other.m_capacity)
	{
		other.m_data = nullptr;
		other.m_size = other.m_capacity = 0;
	}

	// Деструктор
	~CMyArray() noexcept
	{
		Clear();
		operator delete[](m_data);
	}

	// Оператор присваивания (copy-and-swap)
	CMyArray& operator=(CMyArray other)
	{
		swap(other);
		return *this;
	}

	// Добавление элемента в конец
	void PushBack(const T& value)
	{
		if (m_size == m_capacity)
			grow();
		new (m_data + m_size) T(value);
		++m_size;
	}

	// Размер массива
	size_type Size() const noexcept { return m_size; }

	// Оператор доступа с проверкой границ
	T& operator[](size_type index)
	{
		if (index >= m_size)
			throw std::out_of_range("Index out of range");
		return m_data[index];
	}

	const T& operator[](size_type index) const
	{
		if (index >= m_size)
			throw std::out_of_range("Index out of range");
		return m_data[index];
	}

	// Изменение длины массива
	void Resize(size_type newSize)
	{
		if (newSize > m_capacity)
			reserve(newSize);
		if (newSize > m_size)
		{
			// Инициализируем новые элементы значением по умолчанию
			for (size_type i = m_size; i < newSize; ++i)
				new (m_data + i) T();
		}
		else
		{
			// Удаляем избыточные
			for (size_type i = newSize; i < m_size; ++i)
				(m_data + i)->~T();
		}
		m_size = newSize;
	}

	// Удаление всех элементов
	void Clear() noexcept
	{
		for (size_type i = 0; i < m_size; ++i)
			(m_data + i)->~T();
		m_size = 0;
	}

	// Итераторы
	iterator begin() noexcept { return m_data; }
	iterator end() noexcept { return m_data + m_size; }
	const_iterator begin() const noexcept { return m_data; }
	const_iterator end() const noexcept { return m_data + m_size; }

	reverse_iterator rbegin() noexcept { return reverse_iterator(end()); }
	reverse_iterator rend() noexcept { return reverse_iterator(begin()); }
	const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(end()); }
	const_reverse_iterator rend() const noexcept { return const_reverse_iterator(begin()); }

private:
	T* m_data;
	size_type m_size;
	size_type m_capacity;

	// Резервирование памяти
	void reserve(size_type newCapacity)
	{
		T* newData = static_cast<T*>(operator new[](newCapacity * sizeof(T)));
		uninitialized_move(m_data, m_data + m_size, newData);
		Clear();
		operator delete[](m_data);
		m_data = newData;
		m_capacity = newCapacity;
	}

	// Увеличение емкости (удваивает)
	void grow()
	{
		size_type newCap = m_capacity > 0 ? m_capacity * 2 : 1;
		reserve(newCap);
	}

	// Обмен содержимым
	void swap(CMyArray& other) noexcept
	{
		std::swap(m_data, other.m_data);
		std::swap(m_size, other.m_size);
		std::swap(m_capacity, other.m_capacity);
	}

	// Вспомогательные методы для копирования и перемещения элементов без исключений
	static void uninitialized_copy(T* srcBegin, T* srcEnd, T* dst)
	{
		T* cur = dst;
		for (; srcBegin != srcEnd; ++srcBegin, ++cur)
			new (cur) T(*srcBegin);
	}

	static void uninitialized_move(T* srcBegin, T* srcEnd, T* dst)
	{
		T* cur = dst;
		for (; srcBegin != srcEnd; ++srcBegin, ++cur)
			new (cur) T(std::move(*srcBegin));
	}
};

#endif // MY_ARRAY_H
