
#include <gtest/gtest.h>

#include <Flowers/Flower.hpp>

TEST(Flowers_FlowerTest, can_be_created_without_blowing_up)
{
   Flowers::Flower flower;
}

TEST(Flowers_FlowerTest, run__returns_the_expected_response)
{
   Flowers::Flower flower;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, flower.run());
}
