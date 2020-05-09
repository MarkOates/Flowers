
#include <gtest/gtest.h>

#include <Flowers/TitleScreen.hpp>

TEST(Flowers_TitleScreenTest, can_be_created_without_blowing_up)
{
   Flowers::TitleScreen title_screen;
}

TEST(Flowers_TitleScreenTest, primary_timer_func__draws_the_title)
{
   al_init();
   ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);
   Flowers::TitleScreen title_screen;
   title_screen.primary_timer_func();
   al_flip_display();
   sleep(2);
   SUCCEED();
}

