
#include <gtest/gtest.h>

#include <Flowers/LargeTextScroller.hpp>

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>

class Flowers_LargeTextScrollerTest : public ::testing::Test
{
protected:
   ALLEGRO_DISPLAY *display;

   Flowers_LargeTextScrollerTest()
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
      display = al_create_display(800, 600);

      ASSERT_NE(nullptr, display);
   }

   virtual void TearDown() override
   {
      if (al_get_current_display()) al_destroy_display(al_get_current_display());
      al_uninstall_system();
   }

   ALLEGRO_BITMAP *create_text_bitmap(std::string text)
   {
      ALLEGRO_FONT *font = al_create_builtin_font();
      int width = al_get_text_width(font, text.c_str());
      float height = al_get_font_line_height(font);
      ALLEGRO_BITMAP *bitmap = al_create_bitmap(width, height);

      ALLEGRO_STATE previous_state;
      al_store_state(&previous_state, ALLEGRO_STATE_TARGET_BITMAP);

      al_set_target_bitmap(bitmap);
      al_clear_to_color(al_color_name("gray"));
      al_draw_text(font, al_color_name("white"), 0, 0, 0, text.c_str());

      al_restore_state(&previous_state);
      al_destroy_font(font);

      return bitmap;
   }
};

TEST_F(Flowers_LargeTextScrollerTest, can_be_created_without_blowing_up)
{
   Flowers::LargeTextScroller large_text_scroller;
}

// slightly eager test:
TEST_F(Flowers_LargeTextScrollerTest, increment_by_step__will_reposition_the_text_horizontally)
{
   ALLEGRO_BITMAP *text_bitmap = create_text_bitmap("Hello Banner Text!!");

   Flowers::LargeTextScroller large_text_scroller(text_bitmap);

   while(!large_text_scroller.get_finished())
   {
      al_clear_to_color(al_color_name("pink"));
      large_text_scroller.increment_by_step();
      large_text_scroller.draw();
      al_flip_display();
   }

   al_destroy_bitmap(text_bitmap);
}

