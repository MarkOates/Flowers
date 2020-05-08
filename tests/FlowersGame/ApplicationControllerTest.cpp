
#include <gtest/gtest.h>

#include <FlowersGame/ApplicationController.hpp>

TEST(FlowersGame_ApplicationControllerTest, can_be_created_without_blowing_up)
{
   FlowersGame::ApplicationController application_controller;
}

TEST(FlowersGame_ApplicationControllerTest, primary_timer_func__runs_through_the_primary_timer_updates)
{
   FlowersGame::ApplicationController application_controller;
   application_controller.primary_timer_func();
   SUCCEED();
}
