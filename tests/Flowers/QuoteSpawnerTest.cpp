
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

#include <Flowers/QuoteSpawner.hpp>

TEST(Flowers_QuoteSpawnerTest, can_be_created_without_blowing_up)
{
   Flowers::QuoteSpawner quote_spawner;
}

TEST(Flowers_QuoteSpawnerTest, run__returns_the_expected_response)
{
   Flowers::QuoteSpawner quote_spawner;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, quote_spawner.run());
}

