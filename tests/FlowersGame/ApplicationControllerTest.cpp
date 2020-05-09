
#include <gtest/gtest.h>

#include <FlowersGame/ApplicationController.hpp>

TEST(FlowersGame_ApplicationControllerTest, can_be_created_without_blowing_up)
{
   FlowersGame::ApplicationController application_controller;
}

TEST(FlowersGame_ApplicationControllerTest, key_down_func__when_the_escape_key_is_pressed_shuts_down_the_program)
{
   al_init();
   ALLEGRO_DISPLAY *display = al_create_display(800, 600);

   AllegroFlare::Screens screens;
   AllegroFlare::Framework framework(screens);

   FlowersGame::ApplicationController application_controller(&framework, &screens);

   ALLEGRO_EVENT keyboard_event;
   keyboard_event.keyboard.keycode = ALLEGRO_KEY_ESCAPE;

   application_controller.key_down_func(&keyboard_event);

   EXPECT_EQ(true, framework.shutdown_program);

   al_uninstall_system();
}

