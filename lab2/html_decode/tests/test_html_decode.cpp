//
// Created by smmm on 03.03.2025.
//

#include "../src/replace.h"
#include <gtest/gtest.h>
#include <map>
#include <string>

TEST(HtmlDecodeTest, SimpleReplacement)
{
	std::string line = "Hello &quot;world&quot; &amp; everyone";
	DecodeHtmlLine(line);
	EXPECT_EQ(line, "Hello \"world\" & everyone");
}

TEST(HtmlDecodeTest, HTMLTags)
{
	std::string line = "This is a test with &lt;tag&gt; inside";
	DecodeHtmlLine(line);
	EXPECT_EQ(line, "This is a test with <tag> inside");
}

TEST(HtmlDecodeTest, NoEntities)
{
	std::string line = "No entities here";
	DecodeHtmlLine(line);
	EXPECT_EQ(line, "No entities here");
}

TEST(HtmlDecodeTest, IncompleteEntity)
{
	std::string line = "Incomplete entity &quot without end";
	DecodeHtmlLine(line);
	EXPECT_EQ(line, "Incomplete entity &quot without end");
}

TEST(HtmlDecodeTest, MultipleEntities)
{
	std::string line = "Multiple &lt;&gt;&amp;&quot;&apos; entities";
	DecodeHtmlLine(line);
	EXPECT_EQ(line, "Multiple <>&\"' entities");
}

TEST(HtmlDecodeTest, ReplacementAtBoundaries)
{
    std::string line = "&quot;Start and end&quot;";
    DecodeHtmlLine(line);
    EXPECT_EQ(line, "\"Start and end\"");
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
