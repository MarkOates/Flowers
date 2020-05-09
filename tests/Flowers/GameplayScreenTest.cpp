
#include <gtest/gtest.h>

#include <Flowers/GameplayScreen.hpp>

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

TEST(Flowers_GameplayScreenTest, can_be_created_without_blowing_up)
{
   Flowers::GameplayScreen gameplay_screen;
}

TEST(Flowers_GameplayScreenTest, primary_timer_func__renders_the_flowers)
{
   al_init();
   al_init_primitives_addon();

   ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);

   Flowers::GameplayScreen gameplay_screen;
   gameplay_screen.initialize();

   gameplay_screen.primary_timer_func();

   al_flip_display();

   al_uninstall_system();

   SUCCEED();
}

TEST(Flowers_GameplayScreenTest, spawn_quote__will_create_a_new_quote)
{
   al_init();
   al_init_primitives_addon();
   al_init_ttf_addon();
   al_init_font_addon();

   AllegroFlare::FontBin font_bin;
   font_bin.set_full_path("/Users/markoates/Repos/Flowers/bin/programs/data/fonts");
   ASSERT_NE(nullptr, font_bin["Voga-Medium.otf 16"]);
   ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);

   Flowers::GameplayScreen gameplay_screen(&font_bin);
   gameplay_screen.initialize();

   gameplay_screen.spawn_quote();
   int flips = 60;
   for (int i=0; i<flips; i++)
   {
      gameplay_screen.primary_timer_func();
      al_flip_display();
   }

   al_uninstall_system();

   SUCCEED();
}

