//
// Created by smmm on 13.05.2025.
//

#include "httpUrl/HttpUrl.h"

#include <iostream>
int main() {
	int port = 65535;
	HttpUrl url{"aboba.com", "/", Protocol::HTTP, port};
	port = url.GetPort();
	std::cout << port << std::endl;
	return 0;
}