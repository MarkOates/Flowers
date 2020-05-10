
#include <gtest/gtest.h>

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
