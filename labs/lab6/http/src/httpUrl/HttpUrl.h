//
// Created by smmm on 13.05.2025.
//

#ifndef HTTPURL_H
#define HTTPURL_H
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
        std::string const& domain,
        std::string const& document,
        Protocol protocol = HTTP);

    /* инициализирует URL на основе переданных параметров.
        При недопустимости входных параметров выбрасывает исключение
        std::invalid_argument
        Если имя документа не начинается с символа /, то добавляет / к имени документа
    */
    HttpUrl(
        std::string const& domain,
        std::string const& document,
        Protocol protocol,
        Unsigned short port);

    // возвращает строковое представление URL-а. Порт, являющийся стандартным для
    // выбранного протокола (80 для http и 443 для https) в эту строку
    // не должен включаться
    std::string GetURL()const;

    // возвращает доменное имя
    std::string GetDomain()const;

    /*
        Возвращает имя документа. Примеры:
            /
            /index.html
            /images/photo.jpg
    */
    std::string GetDocument()const;

    // возвращает тип протокола
    Protocol GetProtocol()const;

    // возвращает номер порта
    unsigned short GetPort()const;
};



#endif //HTTPURL_H
