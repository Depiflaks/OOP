//
// Created by smmm on 22.05.2025.
//

#ifndef STRINGLIST_H
#define STRINGLIST_H


#include <string>
#include <cstddef>
#include <iterator>
#include "StringListIterator.h"

class StringList {
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

    bool IsEmpty() const;
    size_t GetSize() const;

    using Node = StringListIterator<std::string>::Node;
    using iterator = StringListIterator<std::string>;
    using const_iterator = StringListIterator<const std::string>;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;

    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;

    iterator Insert(const_iterator pos, const std::string& value);
    iterator Erase(const_iterator pos);

private:
    Node* m_head = nullptr;
    Node* m_tail = nullptr;
    size_t m_size = 0;

    void CopyFrom(const StringList& other);
    void MoveFrom(StringList&& other) noexcept;
    void FreeList();
};


#endif //STRINGLIST_H
