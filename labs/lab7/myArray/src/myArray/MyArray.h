//
// Created by smmm on 13.05.2025.
//

#ifndef MY_ARRAY_H
#define MY_ARRAY_H

#include <bits/stl_algo.h>
#include <cstddef>
#include <iterator>
#include <memory>
#include <stdexcept>

template <typename ValueType>
class MyArray
{
public:
	using iterator = ValueType*;
	using const_iterator = const ValueType*;
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
		FreeUpMemory(m_data, m_size);
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

	void PushBack(const ValueType& value)
	{
		if (m_size == m_capacity)
			ResizeWithErrorHandling(m_capacity * 2);
		m_data[m_size + 1] = value;
		++m_size;
	}

	[[nodiscard]] size_t GetSize() const noexcept { return m_size; }

	ValueType& operator[](size_t index)
	{
		CheckIndexInRange(index);
		return m_data[index];
	}

	const ValueType& operator[](size_t index) const
	{
		CheckIndexInRange(index);
		return m_data[index];
	}

	void ResizeWithErrorHandling(const size_t newSize)
	{
		try
		{
			Resize(newSize);
		}
		catch (const std::bad_alloc&)
		{
			throw std::bad_alloc();
		}
	}

	void Clear() noexcept
	{
		FreeUpMemory(m_data, m_size);
		m_data = nullptr;
		m_size = 0;
		m_capacity = 0;
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
	size_t m_size{ 0 };
	size_t m_capacity{ 0 };

	void Resize(const size_t newSize)
	{
		ValueType* newData = nullptr;
		if (newSize <= m_size)
		{
			DestroyObjects(m_data + newSize, m_size - newSize);
			newData = RelocateMemory(newSize);
		}
		else if (newSize <= m_capacity)
		{
			FillEmptyData(m_data + m_size, newSize - m_size);
			newData = RelocateMemory(newSize);
		}
		else
		{
			newData = RelocateMemory(newSize);
			FillEmptyData(newData + m_size, newSize - m_size);
		}
		m_data = newData;
		m_size = newSize;
		m_capacity = newSize;
	}

	ValueType* AllocateMemory(size_t elementCount)
	{
		size_t allocSize = elementCount * sizeof(ValueType);
		ValueType* ptr = std::malloc(allocSize);
		if (ptr == nullptr)
			throw std::bad_alloc();
		return reinterpret_cast<ValueType*>(ptr);
	}

	ValueType* RelocateMemory(size_t elementCount)
	{
		size_t allocSize = elementCount * sizeof(ValueType);
		ValueType* ptr = std::realloc(m_data, allocSize);
		if (ptr == nullptr)
			throw std::bad_alloc();
		return reinterpret_cast<ValueType*>(ptr);
	}

	void DestroyObjects(ValueType* data, size_t elementCount)
	{
		for (size_t i = 0; i < elementCount; ++i)
			data[i].~ValueType();
	}

	void FreeUpMemory(ValueType* data, size_t elementCount)
	{
		DestroyObjects(data, elementCount);
		std::free(data);
	}

	void CopyData(ValueType* to, ValueType* from, size_t copySize)
	{
		size_t createdObjectsCount = 0;
		try
		{
			for (; createdObjectsCount < copySize; ++createdObjectsCount)
				new (to + createdObjectsCount) ValueType(from[createdObjectsCount]);
		}
		catch (...)
		{
			FreeUpMemory(to, createdObjectsCount);
			throw;
		}
	}

	void FillEmptyData(ValueType* to, size_t elementCount)
	{
		CheckTypeHasDefaultConstructor();
		size_t createdObjectsCount = 0;
		try
		{
			for (; createdObjectsCount < elementCount; ++createdObjectsCount)
				new (to + createdObjectsCount) ValueType();
		}
		catch (...)
		{
			FreeUpMemory(to, createdObjectsCount);
			throw;
		}
	}

	void CheckIndexInRange(size_t index) const
	{
		if (index >= m_size)
			throw std::out_of_range("Index out of range: " + std::to_string(index));
	}

	void CheckTypeHasDefaultConstructor()
	{
		static_assert(std::is_default_constructible_v<ValueType>, "Array type must have a default constructor");
	}
};

#endif // MY_ARRAY_H
