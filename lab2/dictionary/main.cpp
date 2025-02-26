//
// Created by smmm on 12.03.2025.
//

#include "src/dialogHandler/DialogHandler.h"
#include "src/dictionary/Dictionary.h"
#include <optional>
#include <stdexcept>
#include <string>

#include <iostream>
#include <ostream>

void RunDialog(const auto& dictFile);
std::optional<std::string> GetInputFilePath(int argc, char** argv);

int main(const int argc, char* argv[])
{
	try
	{
		const auto dictFile = GetInputFilePath(argc, argv);
		RunDialog(dictFile);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
		return EXIT_FAILURE;
	}
	return 0;
}

std::optional<std::string> GetInputFilePath(const int argc, char** argv)
{
	if (argc > 2)
		throw std::invalid_argument("Too many arguments");
	if (argc == 2)
	{
		return argv[1];
	}
	return std::nullopt;
}

void RunDialog(const auto& dictFile)
{
	const DialogHandler dh;
	std::string message;
	auto currentState{ DialogState::waitForWordOrCommand };
	while (currentState != DialogState::exit)
	{
		getline(std::cin, message);
		currentState = dh.HandleMessage(message);
	}
}