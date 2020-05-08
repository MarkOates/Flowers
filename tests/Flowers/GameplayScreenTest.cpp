
#include <gtest/gtest.h>

#include <Flowers/GameplayScreen.hpp>

TEST(Flowers_GameplayScreenTest, can_be_created_without_blowing_up)
{
   Flowers::GameplayScreen gameplay_screen;
}

TEST(Flowers_GameplayScreenTest, run__returns_the_expected_response)
{
   Flowers::GameplayScreen gameplay_screen;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, gameplay_screen.run());
}
