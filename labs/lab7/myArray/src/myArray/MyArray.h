//
// Created by smmm on 13.05.2025.
//

#ifndef MY_ARRAY_H
#define MY_ARRAY_H

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

	void PushBack(const ValueType& value)
	{
		if (m_size == m_capacity)
			Resize(m_capacity * 2);
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

	void Resize(const size_t newSize)
	{
		size_t copySize = std::min(m_size, newSize);
		ValueType* newData = AllocateMemory(newSize);
		CopyData(copySize, newData);
	}

	void Clear() noexcept
	{
		FreeMemory(m_data, m_size);
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

	ValueType* AllocateMemory(size_t elementCount)
	{
		size_t allocSize = elementCount * sizeof(ValueType);
		ValueType* ptr = std::malloc(allocSize);
		if (ptr == nullptr)
			throw std::bad_alloc();
		return reinterpret_cast<ValueType*>(ptr);
	}

	void FreeUpMemory(ValueType* data, size_t elementCount)
	{
		for (size_t i = 0; i < elementCount; ++i)
			data[i].~ValueType();
		std::free(data);
	}

	void CopyData(ValueType* to, ValueType* from, size_t copySize)
	{
		size_t i = 0;
		try
		{
			for (; i < copySize; ++i)
				new (to + i) ValueType(from[i]);
		}
		catch (...)
		{
			FreeUpMemory(to, i);
			throw;
		}
	}

	void CheckIndexInRange(size_t index) const
	{
		if (index >= m_size)
			throw std::out_of_range("Index out of range: " + std::to_string(index));
	}
};

#endif // MY_ARRAY_H
