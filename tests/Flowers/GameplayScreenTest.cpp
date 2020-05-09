
#include <gtest/gtest.h>

#include <Flowers/GameplayScreen.hpp>

#include <allegro5/allegro_primitives.h>

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

   sleep(5);

   al_uninstall_system();

   SUCCEED();
}
