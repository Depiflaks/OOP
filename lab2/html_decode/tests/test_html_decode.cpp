//
// Created by smmm on 03.03.2025.
//

#include "../src/replace.h"
#include <gtest/gtest.h>
#include <map>
#include <string>

struct ReplaceInLineTest : ::testing::Test
{
protected:
	std::map<std::string, std::string> rule{
		{ "quot", "\"" },
		{ "apos", "'" },
		{ "lt", "<" },
		{ "gt", ">" },
		{ "amp", "&" }
	};
};

TEST_F(ReplaceInLineTest, SimpleReplacement)
{
	std::string line = "Hello &quot;world&quot; &amp; everyone";
	ReplaceInLine(rule, line);
	EXPECT_EQ(line, "Hello \"world\" & everyone");
}

TEST_F(ReplaceInLineTest, HTMLTags)
{
	std::string line = "This is a test with &lt;tag&gt; inside";
	ReplaceInLine(rule, line);
	EXPECT_EQ(line, "This is a test with <tag> inside");
}

TEST_F(ReplaceInLineTest, NoEntities)
{
	std::string line = "No entities here";
	ReplaceInLine(rule, line);
	EXPECT_EQ(line, "No entities here");
}

TEST_F(ReplaceInLineTest, IncompleteEntity)
{
	std::string line = "Incomplete entity &quot without end";
	ReplaceInLine(rule, line);
	EXPECT_EQ(line, "Incomplete entity &quot without end");
}

TEST_F(ReplaceInLineTest, MultipleEntities)
{
	std::string line = "Multiple &lt;&gt;&amp;&quot;&apos; entities";
	ReplaceInLine(rule, line);
	EXPECT_EQ(line, "Multiple <>&\"' entities");
}

TEST_F(ReplaceInLineTest, ReplacementAtBoundaries)
{
    std::string line = "&quot;Start and end&quot;";
    ReplaceInLine(rule, line);
    EXPECT_EQ(line, "\"Start and end\"");
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
