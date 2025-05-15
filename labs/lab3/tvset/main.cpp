//
// Created by smmm on 15.05.2025.
//

#include "TVSet.h"

#include <exception/TVSetError.h>
#include <iostream>
#include <sstream>

void ParseAndExecuteCommand(TVSet& tv, const std::string& line)
{
	std::istringstream iss(line);
	std::string command;
	iss >> command;

	if (command == "TurnOn")
		tv.TurnOn();
	else if (command == "TurnOff")
		tv.TurnOff();
	else if (command == "Info")
		tv.Info();
	else if (command == "SelectChannel")
	{
		if (int channel; iss >> channel)
			tv.SelectChannel(channel);
		else
			throw std::invalid_argument("");
	}
	else if (!command.empty())
	{
		throw std::invalid_argument("");
	}
}

void ProcessTvCommands()
{
	std::string line;

	TVSet tv;
	while (std::getline(std::cin, line))
	{
		try
		{
			ParseAndExecuteCommand(tv, line);
		}
		catch (const TVSetError& e)
		{
			std::cerr << "ERROR: " << e.what() << '\n';
		}
		catch (...)
		{
			std::cerr << "[Unknown Error] while processing TV command\n";
		}
	}
}

int main()
{
	ProcessTvCommands();
	return 0;
}
