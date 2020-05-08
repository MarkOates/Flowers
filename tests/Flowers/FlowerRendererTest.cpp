
#include <gtest/gtest.h>

#include <Flowers/FlowerRenderer.hpp>

#include <allegro5/allegro.h>

class Flowers_FlowerRendererTest : public ::testing::Test
{
protected:
   ALLEGRO_DISPLAY *display;

   Flowers_FlowerRendererTest()
      : display(nullptr)
   {
   }

   virtual void SetUp() override
   {
      ASSERT_EQ(false, al_is_system_installed());
      ASSERT_EQ(true, al_init());

      al_set_new_display_flags(ALLEGRO_OPENGL | ALLEGRO_PROGRAMMABLE_PIPELINE);
      ASSERT_EQ(ALLEGRO_OPENGL, al_get_new_display_flags() & ALLEGRO_OPENGL);
      ASSERT_EQ(ALLEGRO_PROGRAMMABLE_PIPELINE, al_get_new_display_flags() & ALLEGRO_PROGRAMMABLE_PIPELINE);
      ALLEGRO_DISPLAY *display = al_create_display(800, 600);

      ASSERT_NE(nullptr, display);
   }

   virtual void TearDown() override
   {
      if (al_get_current_display()) al_destroy_display(al_get_current_display());
      al_uninstall_system();
   }
};


#include <allegro5/allegro_color.h>


TEST_F(Flowers_FlowerRendererTest, DISABLED_can_be_created_without_blowing_up)
{
   Flowers::FlowerRenderer flower_renderer;
}


TEST_F(Flowers_FlowerRendererTest, render__returns_the_expected_response)
{
   Flowers::FlowerRenderer flower_renderer;

   al_clear_to_color(al_color_name("pink"));
   flower_renderer.render();

   al_flip_display();

   sleep(2);
}

