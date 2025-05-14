//
// Created by smmm on 13.05.2025.
//

#include "httpUrl/HttpUrl.h"
#include <iostream>
#include <string>

void AnnotatePrintUrl(const HttpUrl& url)
{
	std::cout << "========================\n";
	std::cout << "URL:       " << url.GetURL() << "\n";
	std::cout << "Protocol:  " << ProtocolToString(url.GetProtocol()) << "\n";
	std::cout << "Domain:    " << url.GetDomain() << "\n";
	std::cout << "Port:      " << url.GetPort() << "\n";
	std::cout << "Document:  " << url.GetDocument() << "\n";
	std::cout << "========================\n";
}

void ProcessInputUrls()
{
	std::string line;
	while (std::getline(std::cin, line))
	{
		try
		{
			const HttpUrl url(line);
			AnnotatePrintUrl(url);
		}
		catch (const UrlParsingError& e)
		{
			std::cerr << "[Parsing Error] " << e.what() << "\n";
		}
		catch (...)
		{
			std::cerr << "[Unknown Error] while processing URL\n";
		}
	}
}

int main()
{
	ProcessInputUrls();
	return 0;
}