
#include <gtest/gtest.h>

#include <Flowers/Gameplay/Board.hpp>

TEST(Flowers_Gameplay_BoardTest, can_be_created_without_blowing_up)
{
   Flowers::Gameplay::Board board;
}

TEST(Flowers_Gameplay_BoardTest, run__returns_the_expected_response)
{
   Flowers::Gameplay::Board board;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, board.run());
}
