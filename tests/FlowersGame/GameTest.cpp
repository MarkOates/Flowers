
#include <gtest/gtest.h>

#include <FlowersGame/Game.hpp>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

TEST(FlowersGame_GameTest, can_be_created_without_blowing_up)
{
   FlowersGame::Game game;
}

TEST(DISABLED_FlowersGame_GameTest, primary_timer_func__draws_the_title)
{
   al_init();
   al_init_font_addon();
   al_init_ttf_addon();

   AllegroFlare::Screens screens;
   AllegroFlare::Framework framework(screens);

   ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);
   AllegroFlare::FontBin font_bin;
   font_bin.set_full_path("/Users/markoates/Repos/Flowers/bin/programs/data/fonts");
   FlowersGame::Game game(&framework, &font_bin);

   game.primary_timer_func();
   al_flip_display();

   //sleep(2);

   font_bin.clear();
   al_uninstall_system();

   SUCCEED();
}

#include <FlowersGame/ProgramRunner.hpp>

TEST(GameRun, run__will_run_the_program)
{
   FlowersGame::ProgramRunner program_runner;

   program_runner.run();

   SUCCEED();
}

