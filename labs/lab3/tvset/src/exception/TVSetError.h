//
// Created by smmm on 15.05.2025.
//

#ifndef TVSETERROR_H
#define TVSETERROR_H
#include <stdexcept>

class TVSetError : public std::runtime_error
{
public:
	using std::runtime_error::runtime_error;
	~TVSetError() override = default;
};

class ChannelOutOfRangeError final : public TVSetError
{
public:
	ChannelOutOfRangeError()
		: TVSetError("ERROR") {};
};

#endif // TVSETERROR_H
