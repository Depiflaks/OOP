//
// Created by smmm on 22.05.2025.
//

#ifndef STRING_LIST_ITERATOR_H
#define STRING_LIST_ITERATOR_H

#include <iterator>
#include <string>
#include <utility>

template <typename T>
class ListIterator
{
public:
	using iterator_category = std::bidirectional_iterator_tag;
	using value_type = std::remove_const_t<T>;
	using reference = T&;
	using pointer = T*;
	using difference_type = std::ptrdiff_t;

	struct Node
	{
		std::string value;
		Node* prev = nullptr;
		Node* next = nullptr;

		explicit Node(std::string val)
			: value(std::move(val))
		{
		}
	};

	explicit ListIterator(Node* node)
		: m_node(node)
	{
	}

	reference operator*() const { return m_node->value; }
	pointer operator->() const { return &m_node->value; }

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

	Node* GetNode() const { return m_node; }

private:
	Node* m_node;
};

#endif // STRING_LIST_ITERATOR_H
