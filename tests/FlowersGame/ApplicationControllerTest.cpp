
#include <gtest/gtest.h>

#include <FlowersGame/ApplicationController.hpp>

TEST(FlowersGame_ApplicationControllerTest, can_be_created_without_blowing_up)
{
   FlowersGame::ApplicationController application_controller;
}

TEST(FlowersGame_ApplicationControllerTest, primary_timer_func__runs_through_the_primary_timer_updates)
{
   al_init();
   ALLEGRO_DISPLAY *display = al_create_display(800, 600);

   FlowersGame::ApplicationController application_controller;
   application_controller.primary_timer_func();

   al_uninstall_system();
}
