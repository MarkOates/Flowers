
#include <gtest/gtest.h>

#include <FlowersGame/Game.hpp>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

TEST(Flowers_GameTest, can_be_created_without_blowing_up)
{
   Flowers::Game game;
}

TEST(Flowers_GameTest, primary_timer_func__draws_the_title)
{
   al_init();
   al_init_font_addon();
   al_init_ttf_addon();

   ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);
   AllegroFlare::FontBin font_bin;
   font_bin.set_full_path("/Users/markoates/Repos/Flowers/bin/programs/data/fonts");
   Flowers::Game game(&font_bin);

   game.primary_timer_func();
   al_flip_display();

   //sleep(2);

   font_bin.clear();
   al_uninstall_system();

   SUCCEED();
}

