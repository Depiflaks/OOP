//
// Created by smmm on 22.05.2025.
//

#include "StringList.h"

StringList::StringList() = default;

StringList::StringList(const StringList& other) {
    CopyFrom(other);
}

StringList::StringList(StringList&& other) noexcept {
    MoveFrom(std::move(other));
}

StringList::~StringList() {
    FreeList();
}

StringList& StringList::operator=(const StringList& other) {
    if (this != &other) {
        FreeList();
        CopyFrom(other);
    }
    return *this;
}

StringList& StringList::operator=(StringList&& other) noexcept {
    if (this != &other) {
        FreeList();
        MoveFrom(std::move(other));
    }
    return *this;
}

void StringList::PushBack(const std::string& value) {
    Node* node = new Node(value);
    node->prev = m_tail;
    if (m_tail) {
        m_tail->next = node;
    } else {
        m_head = node;
    }
    m_tail = node;
    ++m_size;
}

void StringList::PushFront(const std::string& value) {
    Node* node = new Node(value);
    node->next = m_head;
    if (m_head) {
        m_head->prev = node;
    } else {
        m_tail = node;
    }
    m_head = node;
    ++m_size;
}

void StringList::Clear() {
    FreeList();
}

bool StringList::IsEmpty() const {
    return m_size == 0;
}

size_t StringList::GetSize() const {
    return m_size;
}

void StringList::CopyFrom(const StringList& other) {
	const Node* current = other.m_head;
    while (current) {
        PushBack(current->value);
        current = current->next;
    }
}

void StringList::MoveFrom(StringList&& other) noexcept {
    m_head = other.m_head;
    m_tail = other.m_tail;
    m_size = other.m_size;

    other.m_head = nullptr;
    other.m_tail = nullptr;
    other.m_size = 0;
}

void StringList::FreeList() {
	const Node* current = m_head;
    while (current) {
		const Node* next = current->next;
        delete current;
        current = next;
    }
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}
