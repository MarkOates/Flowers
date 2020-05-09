
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

#include <Flowers/LargeTextScroller.hpp>

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro_flare/placement2d.h>

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
      ASSERT_EQ(true, al_init_primitives_addon());

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

   float get_display_center_x()
   {
      return al_get_display_width(display)/2;
   }

   float get_display_middle_y()
   {
      return al_get_display_height(display)/2;
   }

   float get_display_width()
   {
      return al_get_display_width(display);
   }

   float get_display_height()
   {
      return al_get_display_height(display);
   }
};

TEST_F(Flowers_LargeTextScrollerTest, can_be_created_without_blowing_up)
{
   Flowers::LargeTextScroller large_text_scroller;
}

TEST_F(Flowers_LargeTextScrollerTest, draw__with_a_nullptr_bitmap_raises_an_exception)
{
   std::string expected_error_message = "[Flowers::LargeTextScroller.draw() error]: can not have nullptr bitmap";
   Flowers::LargeTextScroller large_text_scroller;
   ASSERT_THROW_WITH_MESSAGE(large_text_scroller.draw(), std::runtime_error, expected_error_message);
}

// slightly eager test:
TEST_F(Flowers_LargeTextScrollerTest, draw__will_render_the_text_aligned_at_the_middle)
{
   ALLEGRO_BITMAP *text_bitmap = create_text_bitmap("Hello Banner Text!!");
   float display_center_x = get_display_center_x();
   float display_middle_y = get_display_middle_y();
   float display_width = get_display_width();
   float display_height = get_display_height();

   Flowers::LargeTextScroller large_text_scroller(text_bitmap);

   al_clear_to_color(al_color_name("pink"));

   allegro_flare::placement2d place(al_get_display_width(display)/2, al_get_display_height(display)/2, 0, 0);
   place.start_transform();

   large_text_scroller.draw();

   place.restore_transform();

   al_draw_line(display_center_x, 0, display_center_x, display_height, al_color_name("blue"), 3.0);
   al_draw_line(0, display_middle_y, display_width, display_middle_y, al_color_name("blue"), 3.0);

   al_flip_display();

   //sleep(2);

   al_destroy_bitmap(text_bitmap);
}

TEST_F(Flowers_LargeTextScrollerTest, increment_by_step__with_a_nullptr_bitmap_raises_an_exception)
{
   al_init_primitives_addon();

   std::string expected_error_message =
      "[Flowers::LargeTextScroller.increment_by_step() error]: can not have nullptr bitmap";
   Flowers::LargeTextScroller large_text_scroller;
   ASSERT_THROW_WITH_MESSAGE(large_text_scroller.increment_by_step(), std::runtime_error, expected_error_message);
}

// slightly eager test:
TEST_F(Flowers_LargeTextScrollerTest, increment_by_step__will_reposition_the_text_horizontally_respecting_scale)
{
   ALLEGRO_BITMAP *text_bitmap = create_text_bitmap("Hello Banner Text!!");

   Flowers::LargeTextScroller large_text_scroller(text_bitmap, 5.0f);
   large_text_scroller.set_scroll_speed(10.0f);

   allegro_flare::placement2d place(al_get_display_width(display)/2, al_get_display_height(display)/2, 0, 0);

   while(!large_text_scroller.get_finished())
   {
      al_clear_to_color(al_color_name("pink"));

      large_text_scroller.increment_by_step();

      place.start_transform();
      large_text_scroller.draw();
      place.restore_transform();

      al_flip_display();
   }

   al_destroy_bitmap(text_bitmap);
}

