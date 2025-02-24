//
// Created by smmm on 10.02.25.
//

#include <cstring>
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>

enum class SourceType
{
	standard = 1,
	files = 5
};

constexpr int helpParametersCount = 2;

const char helpFlag[]{ "-h" };

struct ReplaceConfig
{
	SourceType type{ SourceType::standard };
	std::string inFilePath;
	std::string outFilePath;
	std::string search;
	std::string replace;
};

auto GetSourceType(int argc) -> SourceType;

auto ParseArguments(int argc, char* argv[]) -> ReplaceConfig;

auto Replace(const ReplaceConfig& config) -> void;

auto PrintHelp() -> void;

auto AssertFilesPathsNotEqual(const std::string& filePath1, const std::string& filePath2) -> void;

auto ReplaceInStream(const ReplaceConfig& config, std::istream& inStream, std::ostream& outStream) -> void;

auto ReplaceInLine(const ReplaceConfig& config, std::string& line) -> void;

auto main(const int argc, char* argv[]) -> int
{
	try
	{
		if (argc == helpParametersCount && !strcmp(argv[1], helpFlag))
		{
			PrintHelp();
			return 0;
		}
		const ReplaceConfig config = ParseArguments(argc, argv);
		Replace(config);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}

auto ParseArguments(const int argc, char* argv[]) -> ReplaceConfig
{
	ReplaceConfig config;
	config.type = GetSourceType(argc);
	switch (config.type)
	{
	case SourceType::files:
		config.inFilePath = argv[1];
		config.outFilePath = argv[2];
		config.search = argv[3];
		config.replace = argv[4];
		AssertFilesPathsNotEqual(config.inFilePath, config.outFilePath);
		break;
	case SourceType::standard:
		std::getline(std::cin, config.search);
		std::getline(std::cin, config.replace);
		break;
	}
	return config;
}

auto GetSourceType(const int argc) -> SourceType
{
	switch (argc)
	{
	case 1:
		return SourceType::standard;
	case 5:
		return SourceType::files;
	default:
		throw std::invalid_argument("Invalid parameters count");
	}
}

auto PrintHelp() -> void
{
	std::cout << "Usage:\n"
			  << "  replace.exe <input file> <output file> <search string> <replace string>\n"
			  << "  replace.exe (stdin mode: enter search string, replace string, then text)\n"
			  << "  replace.exe -h (show this help message)\n";
}

auto AssertFilesPathsNotEqual(const std::string& filePath1, const std::string& filePath2) -> void
{
	if (filePath1 == filePath2)
		throw std::runtime_error("Input and output files must be different.");
}

auto Replace(const ReplaceConfig& config) -> void
{
	std::istream* inStream = &std::cin;
	std::ostream* outStream = &std::cout;
	std::ifstream inFile;
	std::ofstream outFile;
	if (config.type == SourceType::files)
	{
		inFile.open(config.inFilePath);
		outFile.open(config.outFilePath);
		if (!inFile || !outFile)
			throw std::runtime_error("Error opening files");
		inStream = &inFile;
		outStream = &outFile;
	}
	ReplaceInStream(config, *inStream, *outStream);
}

auto ReplaceInStream(const ReplaceConfig& config, std::istream& inStream, std::ostream& outStream) -> void
{
	std::string line;
	while (std::getline(inStream, line))
	{
		if (!config.search.empty())
			ReplaceInLine(config, line);
		outStream << line << "\n";
	}
}

auto ReplaceInLine(const ReplaceConfig& config, std::string& line) -> void
{
	size_t pos = 0;
	while ((pos = line.find(config.search, pos)) != std::string::npos)
	{
		line.replace(pos, config.search.length(), config.replace);
		pos += config.replace.length();
	}
}
