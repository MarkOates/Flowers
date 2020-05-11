
#include <gtest/gtest.h>

#include <Flowers/Achievements/Peduncle.hpp>

TEST(Flowers_Achievements_PeduncleTest, can_be_created_without_blowing_up)
{
   Flowers::Achievements::Peduncle peduncle;
}

TEST(Flowers_Achievements_PeduncleTest, run__returns_the_expected_response)
{
   Flowers::Achievements::Peduncle peduncle;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, peduncle.run());
}
