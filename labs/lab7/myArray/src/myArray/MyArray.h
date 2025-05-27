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
		if (other.m_size > 0)
		{
			reserve(other.m_capacity);
			uninitialized_copy(other.m_data, other.m_data + other.m_size, m_data);
			m_size = other.m_size;
		}
	}

	MyArray(MyArray&& other) noexcept
		: m_data(other.m_data)
		, m_size(other.m_size)
		, m_capacity(other.m_capacity)
	{
		other.m_data = nullptr;
		other.m_size = other.m_capacity = 0;
	}

	~MyArray() noexcept
	{
		Clear();
		operator delete[](m_data);
	}

	MyArray& operator=(MyArray other)
	{
		swap(other);
		return *this;
	}

	void PushBack(const value_type& value)
	{
		if (m_size == m_capacity)
			grow();
		new (m_data + m_size) T(value);
		++m_size;
	}

	[[nodiscard]] size_type Size() const noexcept { return m_size; }

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
		if (newSize > m_capacity)
			reserve(newSize);
		if (newSize > m_size)
		{
			for (size_type i = m_size; i < newSize; ++i)
				new (m_data + i) value_type();
		}
		else
		{
			for (size_type i = newSize; i < m_size; ++i)
				(m_data + i)->~T();
		}
		m_size = newSize;
	}

	void Clear() noexcept
	{
		for (size_type i = 0; i < m_size; ++i)
			(m_data + i)->~T();
		m_size = 0;
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

	void reserve(const size_type newCapacity)
	{
		auto newData = static_cast<iterator>(operator new[](newCapacity * sizeof(T)));
		uninitialized_move(m_data, m_data + m_size, newData);
		Clear();
		operator delete[](m_data);
		m_data = newData;
		m_capacity = newCapacity;
	}

	void grow()
	{
		const size_type newCap = m_capacity > 0 ? m_capacity * 2 : 1;
		reserve(newCap);
	}

	void swap(MyArray& other) noexcept
	{
		std::swap(m_data, other.m_data);
		std::swap(m_size, other.m_size);
		std::swap(m_capacity, other.m_capacity);
	}

	static void uninitialized_copy(iterator srcBegin, iterator srcEnd, iterator dst)
	{
		iterator cur = dst;
		for (; srcBegin != srcEnd; ++srcBegin, ++cur)
			new (cur) T(*srcBegin);
	}

	static void uninitialized_move(iterator srcBegin, iterator srcEnd, iterator dst)
	{
		T* cur = dst;
		for (; srcBegin != srcEnd; ++srcBegin, ++cur)
			new (cur) T(std::move(*srcBegin));
	}
};

#endif // MY_ARRAY_H
