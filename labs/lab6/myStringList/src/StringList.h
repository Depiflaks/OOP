//
// Created by smmm on 22.05.2025.
//

#ifndef STRING_LIST_H
#define STRING_LIST_H

#include <cstddef>
#include <iterator/ListIterator.h>
#include <iterator>
#include <string>
#include <utility>

class StringList
{
	struct Node
	{
		std::string value;
		Node* prev = nullptr;
		Node* next = nullptr;

		explicit Node(std::string val)
			: value(std::move(val))
		{
		}

		explicit Node(Node* prev, Node* next)
			: prev(prev)
			, next(next)
		{
		}
	};

public:
	StringList();
	StringList(const StringList& other);
	StringList(StringList&& other) noexcept;
	~StringList();

	StringList& operator=(const StringList& other);
	StringList& operator=(StringList&& other) noexcept;

	void PushBack(const std::string& value);
	void PushFront(const std::string& value);
	void Clear();

	[[nodiscard]] bool IsEmpty() const;
	[[nodiscard]] size_t GetSize() const;

	using iterator = ListIterator<Node, std::string, false>;
	using const_iterator = ListIterator<Node, std::string, true>;
	using reverse_iterator = std::reverse_iterator<iterator>;
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	iterator begin();
	iterator end();
	[[nodiscard]] const_iterator begin() const;
	[[nodiscard]] const_iterator end() const;
	[[nodiscard]] const_iterator cbegin() const;
	[[nodiscard]] const_iterator cend() const;

	[[nodiscard]] reverse_iterator rbegin();
	[[nodiscard]] reverse_iterator rend();
	[[nodiscard]] const_reverse_iterator rbegin() const;
	[[nodiscard]] const_reverse_iterator rend() const;
	[[nodiscard]] const_reverse_iterator crbegin() const;
	[[nodiscard]] const_reverse_iterator crend() const;

	iterator Insert(const iterator& pos, const std::string& v);
	iterator Erase(const iterator& pos);

private:
	Node* m_head = nullptr;
	Node* m_tail = nullptr;
	size_t m_size = 0;
	Node* m_sentinel{ nullptr };

	void CopyFrom(const StringList& other);
	void MoveFrom(StringList&& other) noexcept;
	void FreeList();
	void UpdateTail(Node* newTail);
};

#endif // STRING_LIST_H
