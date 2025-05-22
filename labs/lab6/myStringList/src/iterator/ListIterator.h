//
// Created by smmm on 22.05.2025.
//

#ifndef STRING_LIST_ITERATOR_H
#define STRING_LIST_ITERATOR_H

#include <assert.h>
#include <iterator>
#include <string>
#include <utility>

template <typename NodeType, typename ValueType, bool IsConst>
class ListIterator
{
public:
	using iterator_category = std::bidirectional_iterator_tag;
	using value_type = ValueType;
	using difference_type = std::ptrdiff_t;
	using pointer = std::conditional_t<IsConst, const ValueType*, ValueType*>;
	using reference = std::conditional_t<IsConst, const ValueType&, ValueType&>;

	ListIterator() noexcept
		: m_node(nullptr)
	{
	}
	explicit ListIterator(NodeType* node, NodeType* sentinel) noexcept
		: m_node(node)
		, m_sentinel(sentinel)
	{
	}

	explicit ListIterator(const ListIterator<NodeType, ValueType, false>& other) noexcept
		requires(IsConst)
		: m_node(other.m_node)
	{
	}

	ListIterator(const ListIterator& other) noexcept = default;
	ListIterator& operator=(const ListIterator& other) noexcept = default;

	reference operator*() const
	{
		assert(m_node);
		assert(m_node != m_sentinel);
		return m_node->value;
	}

	pointer operator->() const
	{
		assert(m_node);
		assert(m_node != m_sentinel);
		return &m_node->value;
	}

	ListIterator& operator++() noexcept
	{
		m_node = m_node->next;
		return *this;
	}

	ListIterator operator++(int) noexcept
	{
		ListIterator tmp = *this;
		++(*this);
		return tmp;
	}

	ListIterator& operator--() noexcept
	{
		m_node = m_node->prev;
		return *this;
	}

	ListIterator operator--(int) noexcept
	{
		ListIterator tmp = *this;
		--(*this);
		return tmp;
	}

	template <bool OtherConst>
	bool operator==(const ListIterator<NodeType, ValueType, OtherConst>& other) const noexcept
	{
		return m_node == other.m_node;
	}

	template <bool OtherConst>
	bool operator!=(const ListIterator<NodeType, ValueType, OtherConst>& other) const noexcept
	{
		return !(*this == other);
	}

	NodeType* GetNode() const noexcept { return m_node; }

private:
	NodeType* m_node;
	NodeType* m_sentinel{ nullptr };
};

#endif // STRING_LIST_ITERATOR_H
