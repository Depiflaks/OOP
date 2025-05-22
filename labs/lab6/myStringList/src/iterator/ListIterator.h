//
// Created by smmm on 22.05.2025.
//

#ifndef STRING_LIST_ITERATOR_H
#define STRING_LIST_ITERATOR_H

#include <StringList.h>
#include <iterator>
#include <string>
#include <utility>

struct StringListNode;

template <typename T>
class ListIterator
{
public:
	using iterator_category = std::bidirectional_iterator_tag;
	using value_type = std::remove_const_t<T>;
	using reference = T&;
	using pointer = T*;
	using difference_type = std::ptrdiff_t;
	using raw_value_type = std::remove_const_t<T>;

	using Node = StringListNode;

	explicit ListIterator(Node* node)
		: m_node(node)
	{
	}

	ListIterator(const ListIterator&) = default;
	ListIterator& operator=(const ListIterator&) = default;

	reference operator*() const { return *static_cast<pointer>(&m_node->value); }

	pointer operator->() const { return static_cast<pointer>(&m_node->value); }

	ListIterator& operator++()
	{
		m_node = m_node->next;
		return *this;
	}

	ListIterator operator++(int)
	{
		auto tmp = *this;
		++(*this);
		return tmp;
	}

	ListIterator& operator--()
	{
		m_node = m_node->prev;
		return *this;
	}

	ListIterator operator--(int)
	{
		auto tmp = *this;
		--(*this);
		return tmp;
	}

	bool operator==(const ListIterator& other) const
	{
		return m_node == other.m_node;
	}

	bool operator!=(const ListIterator& other) const
	{
		return !(*this == other);
	}

	[[nodiscard]] Node* GetNode() const { return m_node; }

private:
	Node* m_node;
};

#endif // STRING_LIST_ITERATOR_H
