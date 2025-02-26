//
// Created by smmm on 26.02.2025.
//

#include <fstream>
#include <gtest/gtest.h>
#include <sstream>

const std::string executable = "../main";
const std::vector<std::string> expectedParams{ "$input", "$output", "$search", "$replace" };

struct ReplaceParams
{
	std::string input;
	std::string output;
	std::string search;
	std::string replace;

	explicit ReplaceParams(const std::map<std::string, std::string>& params)
	{
		if (params.find("$input") != params.end())
		{
			input = params.at("$input");
		}
		if (params.find("$output") != params.end())
		{
			output = params.at("$output");
		}
		if (params.find("$search") != params.end())
		{
			search = params.at("$search");
		}
		if (params.find("$replace") != params.end())
		{
			replace = params.at("$replace");
		}
	}
};

auto RunPositiveTest(const std::string& filePath) -> void;
auto ParseTestFile(const std::string& fileName, const std::vector<std::string>& names) -> std::map<std::string, std::string>;
auto ExecuteCommand(const std::string& command) -> std::string;
auto RunSystemStream(const ReplaceParams& params) -> std::string;
auto RunWithFiles(const ReplaceParams& params) -> std::string;
auto CreateTempFile(const std::string& content) -> std::string;
auto WriteToFile(const std::string& filename, const std::string& content) -> bool;

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(ReplaceTest, HelpMessage)
{
	std::string command = executable + " -h";
	std::string output = ExecuteCommand(command);

	EXPECT_TRUE(output.find("Usage") != std::string::npos);
}

TEST(ReplaceTest, EmptySearch)
{
	RunPositiveTest("./files/empty_search.txt");
}

TEST(ReplaceTest, EmptyReplace)
{
	RunPositiveTest("./files/empty_replace.txt");
}

TEST(ReplaceTest, EmptyInput)
{
	RunPositiveTest("./files/empty_input.txt");
}

TEST(ReplaceTest, UniqueSymbol)
{
	RunPositiveTest("./files/unique_symbol.txt");
}

TEST(ReplaceTest, ManySymbols)
{
	RunPositiveTest("./files/many_symbols.txt");
}

TEST(ReplaceTest, SymbolInText)
{
	RunPositiveTest("./files/symbol_in_text.txt");
}

TEST(ReplaceTest, EmptyLines)
{
	RunPositiveTest("./files/empty_lines.txt");
}

TEST(ReplaceTest, SymbolBetweenEmptyLines)
{
	RunPositiveTest("./files/symbol_between_empty_lines.txt");
}

TEST(ReplaceTest, ManySymbolReplace)
{
	RunPositiveTest("./files/many_symbol_replace.txt");
}

TEST(ReplaceTest, NoReplace)
{
	RunPositiveTest("./files/no_replace.txt");
}

TEST(ReplaceTest, InvalidArgumentCount)
{
	std::string command;
	command = executable + " arg1 arg2 2>/dev/null";
	EXPECT_ANY_THROW(ExecuteCommand(command));
	command = executable + " arg1 arg2 arg3 2>/dev/null";
	EXPECT_ANY_THROW(ExecuteCommand(command));
	command = executable + " arg1 arg2 arg3 arg4 arg5 2>/dev/null";
	EXPECT_ANY_THROW(ExecuteCommand(command));
}

TEST(ReplaceTest, DublicatedFiles)
{
	std::string command;
	command = executable + " file.txt file.txt 2>/dev/null";
	EXPECT_ANY_THROW(ExecuteCommand(command));
}

void RunPositiveTest(const std::string& filePath)
{
	auto paramsMap = ParseTestFile(filePath, expectedParams);
	auto params = ReplaceParams(paramsMap);

	auto systemOutput = RunSystemStream(params);
	auto filesOutput = RunWithFiles(params);

	EXPECT_TRUE(systemOutput == params.output);
	EXPECT_TRUE(filesOutput == params.output);
}

auto RunSystemStream(const ReplaceParams& params) -> std::string
{
	std::ostringstream command;
	command << "echo \""
			<< params.search << "\\n"
			<< params.replace << "\\n"
			<< params.input << "\" | " << executable;

	return ExecuteCommand(command.str());
}

auto ExecuteCommand(const std::string& command) -> std::string
{
	std::ostringstream result;
	FILE* pipe = popen(command.c_str(), "r");
	if (!pipe)
		throw std::runtime_error("Failed to open pipe");

	char buffer[128];
	while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
	{
		result << buffer;
	}

	int exitCode = pclose(pipe);
	if (WIFEXITED(exitCode) && WEXITSTATUS(exitCode) != 0)
	{
		throw std::runtime_error("Command failed with exit code: " + std::to_string(WEXITSTATUS(exitCode)));
	}

	return result.str();
}

auto RunWithFiles(const ReplaceParams& params) -> std::string
{
	std::string inputFile = CreateTempFile(params.input);
	std::string outputFile = CreateTempFile("");

	std::ostringstream command;
	command << executable << " " << inputFile << " " << outputFile << " "
			<< "\"" << params.search << "\" "
			<< "\"" << params.replace << "\"";

	std::string result = ExecuteCommand(command.str());

	std::ifstream outFile(outputFile);
	std::string outputContent((std::istreambuf_iterator<char>(outFile)), std::istreambuf_iterator<char>());

	std::remove(inputFile.c_str());
	std::remove(outputFile.c_str());

	return outputContent;
}

auto CreateTempFile(const std::string& content) -> std::string
{
	char filename[L_tmpnam];
	std::tmpnam(filename);
	if (!WriteToFile(filename, content))
	{
		return "";
	}
	return filename;
}

auto WriteToFile(const std::string& filename, const std::string& content) -> bool
{
	std::ofstream file(filename);
	if (!file)
		return false;
	file << content << "\n";
	file.close();
	return true;
}

auto ParseTestFile(const std::string& fileName, const std::vector<std::string>& names) -> std::map<std::string, std::string>
{
	std::ifstream file(fileName);
	std::map<std::string, std::string> parameters;

	if (!file)
	{
		std::cerr << "Error: cannot open file " << fileName << std::endl;
		return parameters;
	}

	std::string line;
	std::string currentParam;
	while (std::getline(file, line))
	{
		if (std::find(names.begin(), names.end(), line) != names.end())
		{
			currentParam = line;

			std::getline(file, line);
			parameters[currentParam] = line;
		}
		else if (!currentParam.empty())
		{
			parameters[currentParam] += "\n" + line;
		}
	}

	return parameters;
}