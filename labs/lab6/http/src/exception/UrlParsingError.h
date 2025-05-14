//
// Created by smmm on 13.05.2025.
//

#ifndef URL_PARSING_ERROR_H
#define URL_PARSING_ERROR_H
#include <stdexcept>

class UrlParsingError : public std::invalid_argument
{
public:
	using std::invalid_argument::invalid_argument;
	~UrlParsingError() override = default;
};

class HttpPatternMissmatchError final : public UrlParsingError
{
public:
	explicit HttpPatternMissmatchError(std::string const& url)
		: UrlParsingError("Given url: \"" + url + "\" does not match HTTP pattern") {};
};

class PortOutOfRangeError final : public UrlParsingError
{
public:
	explicit PortOutOfRangeError(const int port)
		: UrlParsingError("Port " + std::to_string(port) + " is out of range [1, 65535]") {};
};

class EmptyDomainError final : public UrlParsingError
{
public:
	explicit EmptyDomainError()
		: UrlParsingError("Domain name cannot be empty") {};
};

class UnknownProtocolError final : public UrlParsingError
{
public:
	explicit UnknownProtocolError(std::string const& protocol)
		: UrlParsingError("Protocol: \"" + protocol + "\" is unknown") {};
};

#endif // URL_PARSING_ERROR_H
