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
class MyArray
{
public:
	using value_type = T;
	using size_type = std::size_t;
	using iterator = T*;
	using const_iterator = const T*;
	using reverse_iterator = std::reverse_iterator<iterator>;
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	MyArray() noexcept
		: m_data(nullptr)
		, m_size(0)
		, m_capacity(0)
	{
	}

	MyArray(const MyArray& other)
		: m_data(nullptr)
		, m_size(0)
		, m_capacity(0)
	{
		// TODO: реализовать копирующий конструктор
	}

	MyArray(MyArray&& other) noexcept
		: m_data(other.m_data)
		, m_size(other.m_size)
		, m_capacity(other.m_capacity)
	{
		// TODO: реализовать перемещающий конструктор
	}

	~MyArray() noexcept
	{
		// TODO: деструктор
		// Clear();
		// operator delete[](m_data);
	}

	MyArray& operator=(MyArray& other)
	{
		// TODO: оператор копирования
		return *this;
	}

	MyArray& operator=(MyArray&& other) noexcept
	{
		// TODO: оператор перемещения
		return *this;
	}

	void PushBack(const value_type& value)
	{
		// TODO: оператор перемещения
	}

	[[nodiscard]] size_type GetSize() const noexcept { return m_size; }

	value_type& operator[](size_type index)
	{
		if (index >= m_size)
			throw std::out_of_range("Index out of range");
		return m_data[index];
	}

	const value_type& operator[](size_type index) const
	{
		if (index >= m_size)
			throw std::out_of_range("Index out of range");
		return m_data[index];
	}

	void Resize(const size_type newSize)
	{
		// TODO: оператор resize
	}

	void Clear() noexcept
	{
		// TODO: clar
	}

	iterator begin() noexcept { return m_data; }
	iterator end() noexcept { return m_data + m_size; }
	const_iterator begin() const noexcept { return m_data; }
	const_iterator end() const noexcept { return m_data + m_size; }

	reverse_iterator rbegin() noexcept { return reverse_iterator(end()); }
	reverse_iterator rend() noexcept { return reverse_iterator(begin()); }
	const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(end()); }
	const_reverse_iterator rend() const noexcept { return const_reverse_iterator(begin()); }

private:
	iterator m_data;
	size_type m_size;
	size_type m_capacity;

};

#endif // MY_ARRAY_H
