
#include <gtest/gtest.h>

#include <AllegroFlare/FrameworkScreenRegistrar.hpp>

#include <AllegroFlare/Screen.hpp>

class TestScreen : public AllegroFlare::Screen
{
};

TEST(AllegroFlare_FrameworkScreenRegistrarTest, can_be_created_without_blowing_up)
{
   AllegroFlare::FrameworkScreenRegistrar framework_screen_registrar;
}

TEST(AllegroFlare_FrameworkScreenRegistrarTest, append__registers_the_screen_to_the_screens)
{
   AllegroFlare::Screens screens;
   AllegroFlare::Screen screen;

   AllegroFlare::FrameworkScreenRegistrar framework_screen_registrar(&screens, &screen);
   EXPECT_EQ(true, framework_screen_registrar.append());
}

TEST(AllegroFlare_FrameworkScreenRegistrarTest, remove__unregisters_the_screen_to_the_screens)
{
   AllegroFlare::Screens screens;
   AllegroFlare::Screen screen;

   AllegroFlare::FrameworkScreenRegistrar framework_screen_registrar(&screens, &screen);
   EXPECT_EQ(true, framework_screen_registrar.append());

   EXPECT_EQ(true, framework_screen_registrar.remove());
}


