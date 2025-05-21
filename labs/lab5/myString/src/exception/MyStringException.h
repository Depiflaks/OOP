//
// Created by smmm on 21.05.2025.
//

#ifndef MYSTRINGEXCEPTION_H
#define MYSTRINGEXCEPTION_H
#include <stdexcept>

class MyStringException : public std::runtime_error
{
public:
	using std::runtime_error::runtime_error;
	~MyStringException() override = default;
};

class IndexOutOfRangeException final : public MyStringException
{
public:
	explicit IndexOutOfRangeException(const size_t index)
		: MyStringException("index: " + std::to_string(index) + " is out of range") {};
};

#endif // MYSTRINGEXCEPTION_H
