//
// Created by smmm on 13.05.2025.
//

#ifndef HTTP_URL_H
#define HTTP_URL_H

#include <regex>
#include <string>

enum class Protocol
{
	HTTP,
	HTTPS
};

class HttpUrl
{
public:
	// выполняет парсинг строкового представления URL-а, в случае ошибки парсинга
	// выбрасывает исключение CUrlParsingError, содержащее текстовое описание ошибки
	HttpUrl(std::string const& url);

	/* инициализирует URL на основе переданных параметров.
		При недопустимости входных параметров выбрасывает исключение
		std::invalid_argument
		Если имя документа не начинается с символа /, то добавляет / к имени документа
	*/
	HttpUrl(
		std::string domain,
		std::string document,
		Protocol protocol = Protocol::HTTP);

	/* инициализирует URL на основе переданных параметров.
		При недопустимости входных параметров выбрасывает исключение
		std::invalid_argument
		Если имя документа не начинается с символа /, то добавляет / к имени документа
	*/
	HttpUrl(
		std::string domain,
		std::string document,
		Protocol protocol,
		unsigned short port);

	// возвращает строковое представление URL-а. Порт, являющийся стандартным для
	// выбранного протокола (80 для http и 443 для https) в эту строку
	// не должен включаться
	std::string GetURL() const;

	// возвращает доменное имя
	std::string GetDomain() const;

	/*
		Возвращает имя документа. Примеры:
			/
			/index.html
			/images/photo.jpg
	*/
	std::string GetDocument() const;

	// возвращает тип протокола
	Protocol GetProtocol() const;

	// возвращает номер порта
	unsigned short GetPort() const;

private:
	std::string m_url;
	std::string m_domain;
	std::string m_document;
	Protocol m_protocol;
	unsigned short m_port;

	const unsigned short k_httpPort{ 80 };
	const unsigned short k_httpsPort{ 443 };

	const unsigned short k_minPort{ 1 };
	const unsigned short k_maxPort{ 65535 };

	const std::regex k_urlRegex{ R"(^(\w+)://([^/:?#]+)(?::(\d+))?([^?#]*)$)",
		std::regex::icase };

	void SetStandardPort();
};

#endif // HTTP_URL_H
