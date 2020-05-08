
#include <gtest/gtest.h>

#include <Flowers/LargeTextScroller.hpp>

TEST(Flowers_LargeTextScrollerTest, can_be_created_without_blowing_up)
{
   Flowers::LargeTextScroller large_text_scroller;
}

TEST(Flowers_LargeTextScrollerTest, run__returns_the_expected_response)
{
   Flowers::LargeTextScroller large_text_scroller;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, large_text_scroller.run());
}
