//
// Created by smmm on 13.05.2025.
//

#include "HttpUrl.h"

#include "exception/UrlParsingError.h"

#include <utility>

HttpUrl::HttpUrl(std::string const& url)
{
	std::smatch match;
	if (!std::regex_match(url, match, k_urlRegex))
		throw HttpPatternMissmatchError(url);

	SetProtocol(match[1].str());
	SetDomain(match[2].str());
	if (match[3].matched)
		SetPort(std::stoi(match[3]));
	else
		SetStandardPort();
	SetDocument(match[4].str());

	CollectUrl();
}

HttpUrl::HttpUrl(const std::string& domain, const std::string& document, const Protocol protocol)
	: m_domain{}
	, m_document{}
	, m_protocol{ protocol }
	, m_port{}
{
	SetDomain(domain);
	SetDocument(document);
	SetStandardPort();
	CollectUrl();
}

HttpUrl::HttpUrl(const std::string& domain, const std::string& document, const Protocol protocol, const int port)
	: m_domain{}
	, m_document{}
	, m_protocol{ protocol }
	, m_port{}
{
	SetDomain(domain);
	SetDocument(document);
	SetPort(port);
	CollectUrl();
}

std::string HttpUrl::GetURL() const
{
	return m_url;
}

std::string HttpUrl::GetDomain() const
{
	return m_domain;
}

void HttpUrl::SetDomain(const std::string& newDomain)
{
	CheckDomainNotEmpty(newDomain);
	m_domain = ToLower(newDomain);
}

std::string HttpUrl::GetDocument() const
{
	return m_document;
}

void HttpUrl::SetDocument(const std::string& newDocument)
{
	m_document = newDocument;
	if (m_document.empty() || m_document[0] != '/')
		m_document = "/" + m_document;
}

Protocol HttpUrl::GetProtocol() const
{
	return m_protocol;
}

void HttpUrl::SetProtocol(const std::string& newProtocol)
{
	m_protocol = StringToProtocol(ToLower(newProtocol));
}

unsigned short HttpUrl::GetPort() const
{
	return m_port;
}

void HttpUrl::SetPort(const int newPort)
{
	CheckPort(newPort);
	m_port = static_cast<unsigned short>(newPort);
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

void HttpUrl::CollectUrl()
{
	std::ostringstream oss;

	oss << ProtocolToString(m_protocol) << k_schemeSeparator << m_domain;

	if ((m_protocol == Protocol::HTTP && m_port != k_httpPort)
		|| (m_protocol == Protocol::HTTPS && m_port != k_httpsPort))
		oss << ':' << m_port;

	if (!m_document.empty() && m_document[0] != '/')
		oss << '/' << m_document;
	else
		oss << m_document;

	m_url = oss.str();
}

void HttpUrl::CheckPort(const int port) const
{
	if (port < k_minPort || port > k_maxPort)
		throw PortOutOfRangeError(m_port);
}

void HttpUrl::CheckDomainNotEmpty(const std::string& domain)
{
	if (domain.empty())
		throw EmptyDomainError();
}

std::string HttpUrl::ToLower(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(),
		[](const unsigned char c) { return static_cast<char>(std::tolower(c)); });
	return str;
}
