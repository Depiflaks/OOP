//
// Created by smmm on 13.03.2025.
//

#include <gtest/gtest.h>
#include "../src/dictionary/Dictionary.h"

using DictionaryType = std::map<std::string, std::set<std::string>>;

TEST(DictionaryTest, DefaultConstructorCreatesEmptyDictionary) {
    Dictionary dict;
    EXPECT_TRUE(dict.GetDictionary().empty());
}

TEST(DictionaryTest, ConstructorWithDataInitializesCorrectly) {
    DictionaryType initialData = {{"hello", {"привет"}}, {"world", {"мир"}}};
    Dictionary dict(initialData);
    auto result = dict.GetDictionary();

    EXPECT_EQ(result.size(), 2u);
    EXPECT_EQ(result.at("hello"), std::set<std::string>{"привет"});
    EXPECT_EQ(result.at("world"), std::set<std::string>{"мир"});
}

TEST(DictionaryTest, StoreAddsNewKeyWithTranslations) {
    Dictionary dict;
    dict.Store("apple", {"яблоко"});

    auto result = dict.Find("apple");
    ASSERT_TRUE(result.has_value());
    EXPECT_EQ(result.value(), std::set<std::string>{"яблоко"});

    auto reverseResult = dict.Find("яблоко");
    ASSERT_TRUE(reverseResult.has_value());
    EXPECT_EQ(reverseResult.value(), std::set<std::string>{"apple"});
}

TEST(DictionaryTest, StoreUpdatesExistingKey) {
    Dictionary dict;
    dict.Store("apple", {"яблоко"});
    dict.Store("apple", {"яблоку"});

    auto result = dict.Find("apple");
    ASSERT_TRUE(result.has_value());
    EXPECT_EQ(result.value(), (std::set<std::string>{"яблоко", "яблоку"}));
}

TEST(DictionaryTest, ReverseTranslationIsStoredByDefault) {
    Dictionary dict;
    dict.Store("hello", {"привет", "здравствуйте"});

    auto ruResult = dict.Find("привет");
    ASSERT_TRUE(ruResult.has_value());
    EXPECT_EQ(ruResult.value(), std::set<std::string>{"hello"});

    auto ruResult2 = dict.Find("здравствуйте");
    ASSERT_TRUE(ruResult2.has_value());
    EXPECT_EQ(ruResult2.value(), std::set<std::string>{"hello"});
}

TEST(DictionaryTest, NoReverseTranslationWhenFlagIsFalse) {
    Dictionary dict;
    dict.Store("hello", {"привет"}, false);

    auto reverseResult = dict.Find("привет");
    EXPECT_FALSE(reverseResult.has_value());
}

TEST(DictionaryTest, FindNonExistentKeyReturnsNullopt) {
    Dictionary dict;
    auto result = dict.Find("unknown");
    EXPECT_FALSE(result.has_value());
}

TEST(DictionaryTest, StoreThrowsOnEmptyKey) {
    Dictionary dict;
    EXPECT_THROW(dict.Store("", {"translation"}), std::invalid_argument);
}

TEST(DictionaryTest, StoreThrowsOnEmptyTranslations) {
    Dictionary dict;
    EXPECT_THROW(dict.Store("key", {}), std::invalid_argument);
}

TEST(DictionaryTest, StoreThrowsOnEmptyTranslationString) {
    Dictionary dict;
    EXPECT_THROW(dict.Store("key", {"", "translation"}), std::invalid_argument);
}

TEST(DictionaryTest, MultipleReverseTranslationsAreStored) {
    Dictionary dict;
    dict.Store("car", {"автомобиль", "машина"});

    auto ruResult1 = dict.Find("автомобиль");
    ASSERT_TRUE(ruResult1.has_value());
    EXPECT_EQ(ruResult1.value(), std::set<std::string>{"car"});

    auto ruResult2 = dict.Find("машина");
    ASSERT_TRUE(ruResult2.has_value());
    EXPECT_EQ(ruResult2.value(), std::set<std::string>{"car"});
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
