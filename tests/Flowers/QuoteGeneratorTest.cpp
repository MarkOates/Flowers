
#include <gtest/gtest.h>

#include <Flowers/QuoteGenerator.hpp>

TEST(Flowers_QuoteGeneratorTest, can_be_created_without_blowing_up)
{
   Flowers::QuoteGenerator quote_generator;
}

TEST(Flowers_QuoteGeneratorTest, run__returns_the_expected_response)
{
}

TEST(Flowers_QuoteGeneratorTest, generate_quote__returns_the_expected_response)
{
   Flowers::QuoteGenerator quote_generator;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, quote_generator.generate_quote());
}
