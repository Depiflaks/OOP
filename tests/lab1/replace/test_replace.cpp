//
// Created by smmm on 26.02.2025.
//

#include <fstream>
#include <gtest/gtest.h>
#include <sstream>

const std::string executable = "./main";
const std::vector<std::string> expectedParams{ "input", "output", "search", "replace" };

struct ReplaceParams
{
	std::string input;
	std::string output;
	std::string search;
	std::string replace;

	explicit ReplaceParams(const std::map<std::string, std::string>& params)
	{
		if (params.find("input") != params.end())
		{
			input = params.at("input");
		}
		if (params.find("output") != params.end())
		{
			output = params.at("output");
		}
		if (params.find("search") != params.end())
		{
			search = params.at("search");
		}
		if (params.find("replace") != params.end())
		{
			replace = params.at("replace");
		}
	}
};

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

// Test: help flag
TEST(ReplaceTest, HelpMessage)
{
	std::string command = executable + " -h";
	std::string output = ExecuteCommand(command);

	EXPECT_TRUE(output.find("Usage") != std::string::npos);
}

// Test: empty "search" string
TEST(ReplaceTest, EmptySearch)
{
	auto paramsMap = ParseTestFile("./files/test1.txt", expectedParams);
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
		return "ERROR";
	char buffer[128];
	while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
	{
		result << buffer;
	}
	pclose(pipe);
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
	file << content;
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
			parameters[currentParam] = "";
		}
		else if (!currentParam.empty())
		{
			if (!parameters[currentParam].empty())
				parameters[currentParam] += "\n";
			parameters[currentParam] += line;
		}
	}

	return parameters;
}