//
// Created by smmm on 21.05.2025.
//

#ifndef MY_STRING_ITERATOR_H
#define MY_STRING_ITERATOR_H
#include <assert.h>
#include <cstddef>
#include <iterator>

template <typename T>
class MyStringIterator
{
public:
	using value_type = T;
	using pointer = T*;
	using reference = T&;
	using difference_type = std::ptrdiff_t;
	using iterator_category = std::random_access_iterator_tag;

	MyStringIterator() = default;

	MyStringIterator(pointer ptr, pointer begin, pointer end)
		: m_ptr(ptr)
		, m_begin(begin)
		, m_end(end)
	{
	}

	reference operator*() const
	{
		assert(m_ptr);
		assert(m_ptr >= m_begin && m_ptr < m_end);
		return *m_ptr;
	}

	reference operator[](difference_type offset) const
	{
		pointer p = m_ptr + offset;
		assert(p >= m_begin && p < m_end);
		return *p;
	}

	MyStringIterator& operator++()
	{
		++m_ptr;
		return *this;
	}

	MyStringIterator operator++(int)
	{
		MyStringIterator tmp = *this;
		++*this;
		return tmp;
	}

	MyStringIterator& operator--()
	{
		--m_ptr;
		return *this;
	}

	MyStringIterator operator--(int)
	{
		MyStringIterator tmp = *this;
		--*this;
		return tmp;
	}

	MyStringIterator& operator+=(difference_type offset)
	{
		m_ptr += offset;
		return *this;
	}

	MyStringIterator operator+(difference_type offset) const
	{
		return MyStringIterator(m_ptr + offset, m_begin, m_end);
	}

	friend MyStringIterator operator+(difference_type offset, MyStringIterator const& it)
	{
		return it + offset;
	}

	MyStringIterator& operator-=(difference_type offset)
	{
		m_ptr -= offset;
		return *this;
	}

	MyStringIterator operator-(difference_type offset) const
	{
		return MyStringIterator(m_ptr - offset, m_begin, m_end);
	}

	difference_type operator-(const MyStringIterator& other) const
	{
		return m_ptr - other.m_ptr;
	}

	auto operator<=>(const MyStringIterator&) const = default;

private:
	pointer m_ptr = nullptr;
	pointer m_begin = nullptr;
	pointer m_end = nullptr;
};

#endif // MY_STRING_ITERATOR_H
