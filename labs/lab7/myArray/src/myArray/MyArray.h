//
// Created by smmm on 13.05.2025.
//

#ifndef MY_ARRAY_H
#define MY_ARRAY_H

#include <cstddef>
#include <iterator>
#include <memory>
#include <stdexcept>

template <typename valueType>
class MyArray
{
public:
	using iterator = valueType*;
	using const_iterator = const valueType*;
	using reverse_iterator = std::reverse_iterator<iterator>;
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	MyArray() noexcept = default;

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

	void PushBack(const valueType& value)
	{
		if (m_size == m_capacity)
			Resize(m_capacity * 2);
		m_data[m_size + 1] = value;
		++m_size;
	}

	[[nodiscard]] std::size_t GetSize() const noexcept { return m_size; }

	valueType& operator[](std::size_t index)
	{
		if (index >= m_size)
			throw std::out_of_range("Index out of range");
		return m_data[index];
	}

	const valueType& operator[](std::size_t index) const
	{
		if (index >= m_size)
			throw std::out_of_range("Index out of range");
		return m_data[index];
	}

	void Resize(const std::size_t newSize)
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
	iterator m_data{ nullptr };
	std::size_t m_size{ 0 };
	std::size_t m_capacity{ 0 };
};

#endif // MY_ARRAY_H
