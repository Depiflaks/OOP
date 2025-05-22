//
// Created by smmm on 22.05.2025.
//

#ifndef STRINGLIST_H
#define STRINGLIST_H

#include <cstddef>
#include <iterator/StringListIterator.h>
#include <iterator>
#include <string>

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

    [[nodiscard]] bool IsEmpty() const;
    [[nodiscard]] size_t GetSize() const;

    using Node = ListIterator<std::string>::Node;
    using iterator = ListIterator<std::string>;
    using const_iterator = ListIterator<const std::string>;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    iterator begin();
    iterator end();
    [[nodiscard]] const_iterator begin() const;
    [[nodiscard]] const_iterator end() const;
    [[nodiscard]] const_iterator cbegin() const;
    [[nodiscard]] const_iterator cend() const;

    reverse_iterator rbegin();
    reverse_iterator rend();
    [[nodiscard]] const_reverse_iterator rbegin() const;
    [[nodiscard]] const_reverse_iterator rend() const;
    [[nodiscard]] const_reverse_iterator crbegin() const;
    [[nodiscard]] const_reverse_iterator crend() const;

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
