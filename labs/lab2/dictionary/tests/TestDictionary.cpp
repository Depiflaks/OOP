//
// Created by smmm on 13.03.2025.
//

#include "../src/dictionary/Dictionary.h"
#include <gtest/gtest.h>

using DictionaryType = std::map<std::string, std::set<std::string>>;

TEST(DictionaryTest, DefaultConstructorCreatesEmptyDictionary)
{
	Dictionary dict;
	EXPECT_TRUE(dict.GetDictionary().empty());
}

TEST(DictionaryTest, ConstructorWithDataInitializesCorrectly)
{
	DictionaryType initialData = { { "hello", { "привет" } }, { "world", { "мир" } } };
	Dictionary dict(initialData);
	auto result = dict.GetDictionary();

	EXPECT_EQ(result.size(), 2u);
	EXPECT_EQ(result.at("hello"), std::set<std::string>{ "привет" });
	EXPECT_EQ(result.at("world"), std::set<std::string>{ "мир" });
}

TEST(DictionaryTest, StoreAddsNewKeyWithTranslations)
{
	Dictionary dict;
	dict.Store("apple", { "яблоко" });

	auto result = dict.Find("apple");
	ASSERT_TRUE(result.has_value());
	EXPECT_EQ(result.value(), std::set<std::string>{ "яблоко" });

	auto reverseResult = dict.Find("яблоко");
	ASSERT_TRUE(reverseResult.has_value());
	EXPECT_EQ(reverseResult.value(), std::set<std::string>{ "apple" });
}

TEST(DictionaryTest, StoreUpdatesExistingKey)
{
	Dictionary dict;
	dict.Store("apple", { "яблоко" });
	dict.Store("apple", { "яблоку" });

	auto result = dict.Find("apple");
	ASSERT_TRUE(result.has_value());
	EXPECT_EQ(result.value(), (std::set<std::string>{ "яблоко", "яблоку" }));
}

TEST(DictionaryTest, ReverseTranslationIsStoredByDefault)
{
	Dictionary dict;
	dict.Store("hello", { "привет", "здравствуйте" });

	auto ruResult = dict.Find("привет");
	ASSERT_TRUE(ruResult.has_value());
	EXPECT_EQ(ruResult.value(), std::set<std::string>{ "hello" });

	auto ruResult2 = dict.Find("здравствуйте");
	ASSERT_TRUE(ruResult2.has_value());
	EXPECT_EQ(ruResult2.value(), std::set<std::string>{ "hello" });
}

TEST(DictionaryTest, FindNonExistentKeyReturnsNullopt)
{
	Dictionary dict;
	auto result = dict.Find("unknown");
	EXPECT_FALSE(result.has_value());
}

TEST(DictionaryTest, StoreThrowsOnEmptyKey)
{
	Dictionary dict;
	EXPECT_THROW(dict.Store("", { "translation" }), std::invalid_argument);
}

TEST(DictionaryTest, StoreThrowsOnEmptyTranslations)
{
	Dictionary dict;
	EXPECT_THROW(dict.Store("key", {}), std::invalid_argument);
}

TEST(DictionaryTest, StoreThrowsOnEmptyTranslationString)
{
	Dictionary dict;
	EXPECT_THROW(dict.Store("key", { "", "translation" }), std::invalid_argument);
}

TEST(DictionaryTest, MultipleReverseTranslationsAreStored)
{
	Dictionary dict;
	dict.Store("car", { "автомобиль", "машина" });

	auto ruResult1 = dict.Find("автомобиль");
	ASSERT_TRUE(ruResult1.has_value());
	EXPECT_EQ(ruResult1.value(), std::set<std::string>{ "car" });

	auto ruResult2 = dict.Find("машина");
	ASSERT_TRUE(ruResult2.has_value());
	EXPECT_EQ(ruResult2.value(), std::set<std::string>{ "car" });
}
TEST(DictionaryTest, StoreKeyWithDifferentCases)
{
	Dictionary dict;
	dict.Store("Apple", { "fruit" });
	dict.Store("BANANA", { "fruit" });
	dict.Store("CherRY", { "fruit" });

	DictionaryType data = dict.GetDictionary();

	EXPECT_EQ(data.count("apple"), 1u);
	EXPECT_EQ(data.count("banana"), 1u);
	EXPECT_EQ(data.count("cherry"), 1u);
	EXPECT_EQ(data.count("Apple"), 0u);
}

TEST(DictionaryTest, StoreTranslationsWithDifferentCases)
{
	Dictionary dict;
	dict.Store("fruit", { "APPLE", "BANANA", "CHERRY" });

	auto result = dict.Find("fruit");
	ASSERT_TRUE(result.has_value());
	EXPECT_EQ(result.value(), (std::set<std::string>{ "apple", "banana", "cherry" }));
}

TEST(DictionaryTest, ReverseTranslationWithCaseInsensitivity)
{
	Dictionary dict;
	dict.Store("Apple", { "FRUIT" });
	dict.Store("Banana", { "FRUIT", "Berry" });

	auto fruitTranslations = dict.Find("fruit");
	ASSERT_TRUE(fruitTranslations.has_value());
	EXPECT_EQ(fruitTranslations.value(), (std::set<std::string>{ "apple", "banana" }));

	auto berryTranslations = dict.Find("berry");
	ASSERT_TRUE(berryTranslations.has_value());
	EXPECT_EQ(berryTranslations.value(), std::set<std::string>{ "banana" });
}

TEST(DictionaryTest, FindIsCaseInsensitive)
{
	Dictionary dict;
	dict.Store("apple", { "fruit" });

	EXPECT_TRUE(dict.Find("APPLE").has_value());
	EXPECT_TRUE(dict.Find("Apple").has_value());
	EXPECT_TRUE(dict.Find("apple").has_value());
	EXPECT_FALSE(dict.Find("APPL").has_value());
}

TEST(DictionaryTest, DuplicateKeysWithDifferentCases)
{
	Dictionary dict;
	dict.Store("APPLE", { "red" });
	dict.Store("apple", { "green" });
	dict.Store("Apple", { "yellow" });

	auto result = dict.Find("apple");
	ASSERT_TRUE(result.has_value());
	EXPECT_EQ(result.value(), (std::set<std::string>{ "green", "red", "yellow" }));
}

TEST(DictionaryTest, MixedCaseTranslationsMerge)
{
	Dictionary dict;
	dict.Store("fruit", { "APPLE" });
	dict.Store("FRUIT", { "BANANA" });
	dict.Store("Fruit", { "CHERRY" });

	auto result = dict.Find("fruit");
	ASSERT_TRUE(result.has_value());
	EXPECT_EQ(result.value(), (std::set<std::string>{ "apple", "banana", "cherry" }));
}

TEST(DictionaryTest, CaseInsensitiveReverseMapping)
{
	Dictionary dict;
	dict.Store("APPLE", { "FRUIT", "FOOD" });
	dict.Store("ORANGE", { "FRUIT", "COLOR" });

	auto fruitTranslations = dict.Find("fruit");
	ASSERT_TRUE(fruitTranslations.has_value());
	EXPECT_EQ(fruitTranslations.value(), (std::set<std::string>{ "apple", "orange" }));

	auto colorTranslations = dict.Find("color");
	ASSERT_TRUE(colorTranslations.has_value());
	EXPECT_EQ(colorTranslations.value(), std::set<std::string>{ "orange" });
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
