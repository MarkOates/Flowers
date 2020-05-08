
#include <gtest/gtest.h>

#include <Flowers/GameplayScreen.hpp>

TEST(Flowers_GameplayScreenTest, can_be_created_without_blowing_up)
{
   Flowers::GameplayScreen gameplay_screen;
}

TEST(Flowers_GameplayScreenTest, primary_timer_func__runs_through_the_primary_timer_updates)
{
   Flowers::GameplayScreen gameplay_screen;
   gameplay_screen.primary_timer_func();
   SUCCEED();
}
