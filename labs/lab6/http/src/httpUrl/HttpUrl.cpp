//
// Created by smmm on 13.05.2025.
//

#include "HttpUrl.h"

#include <utility>

HttpUrl::HttpUrl(std::string const& url)
{
}

void HttpUrl::SetStandardPort()
{
	switch (m_protocol)
	{
	case Protocol::HTTP:
		m_port = k_httpPort;
		break;
	case Protocol::HTTPS:
		m_port = k_httpsPort;
		break;
	}
}

HttpUrl::HttpUrl(std::string domain, std::string document, const Protocol protocol)
	: m_domain(std::move(domain))
	, m_document(std::move(document))
	, m_protocol(protocol)
	, m_port(80)
{
	SetStandardPort();
	m_url = m_domain + "/" + m_document;
}

HttpUrl::HttpUrl(std::string domain, std::string  document, const Protocol protocol, const unsigned short port)
	: m_domain(std::move(domain))
	, m_document(std::move(document))
	, m_protocol(protocol)
	, m_port(port)
{
}

std::string HttpUrl::GetURL() const
{
	return m_url;
}

std::string HttpUrl::GetDomain() const
{
	return m_domain;
}

std::string HttpUrl::GetDocument() const
{
	return m_document;
}

Protocol HttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short HttpUrl::GetPort() const
{
	return m_port;
}