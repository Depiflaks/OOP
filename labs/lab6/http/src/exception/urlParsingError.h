//
// Created by smmm on 13.05.2025.
//

#ifndef URL_PARSING_ERROR_H
#define URL_PARSING_ERROR_H
#include <stdexcept>

class UrlParsingError final : public std::invalid_argument
{
public:
	UrlParsingError()
		: std::invalid_argument("UrlParsingError") {};
};

#endif // URL_PARSING_ERROR_H
