//
// Created by smmm on 13.05.2025.
//

#include "HttpUrl.h"

#include "exception/UrlParsingError.h"

#include <optional>
#include <utility>

struct UrlParameters
{
	explicit UrlParameters(std::smatch& match)
	{
		m_protocol = match[1].str();
		m_domain = match[2].str();
		if (match[3].matched)
			m_port = std::stoi(match[3]);
		else
			m_port = std::nullopt;
		m_document = match[4].str();
	}

	std::string m_domain;
	std::string m_document;
	std::string m_protocol;
	std::optional<int> m_port;
};

HttpUrl::HttpUrl(std::string const& url)
{
	std::smatch match;
	if (!std::regex_match(url, match, k_urlRegex))
		throw HttpPatternMissmatchError(url);

	const UrlParameters params(match);
	m_protocol = StringToProtocol(ToLower(params.m_protocol));
	m_domain = ToLower(params.m_domain);

	if (params.m_port.has_value())
	{
		CheckPort(*params.m_port);
		m_port = static_cast<unsigned short>(*params.m_port);
	}
	else
		SetStandardPort();

	m_document = FormatDocument(params.m_document);

	CollectUrl();
}

HttpUrl::HttpUrl(std::string domain, std::string document, const Protocol protocol)
	: m_domain(ToLower(std::move(domain)))
	, m_document(FormatDocument(std::move(document)))
	, m_protocol(protocol)
	, m_port(80)
{
	CheckDomainNotEmpty();
	SetStandardPort();
	CollectUrl();
}

HttpUrl::HttpUrl(std::string domain, std::string document, const Protocol protocol, const int port)
	: m_domain(ToLower(std::move(domain)))
	, m_document(FormatDocument(std::move(document)))
	, m_protocol(protocol)
	, m_port()
{
	CheckDomainNotEmpty();
	CheckPort(port);
	m_port = port;
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

std::string HttpUrl::FormatDocument(std::string document)
{
	if (document.empty() || document[0] != '/')
		document = "/" + document;
	return document;
}

void HttpUrl::CheckPort(const int port) const
{
	if (port < k_minPort || port > k_maxPort)
		throw PortOutOfRangeError(m_port);
}

void HttpUrl::CheckDomainNotEmpty() const
{
	if (m_domain.empty())
		throw EmptyDomainError();
}

std::string HttpUrl::ToLower(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(),
		[](const unsigned char c) { return static_cast<char>(std::tolower(c)); });
	return str;
}
