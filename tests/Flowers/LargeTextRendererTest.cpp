
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

#include <Flowers/LargeTextRenderer.hpp>

#include <allegro5/allegro_color.h>

class Flowers_LargeTextRendererTest : public ::testing::Test
{
protected:
   ALLEGRO_DISPLAY *display;

   Flowers_LargeTextRendererTest()
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
};

TEST_F(Flowers_LargeTextRendererTest, can_be_created_without_blowing_up)
{
   Flowers::LargeTextRenderer large_text_renderer;
}

TEST_F(Flowers_LargeTextRendererTest, render__with_a_nullptr_font_raises_an_exception)
{
   Flowers::LargeTextRenderer large_text_renderer;
   std::string expected_error_message = "[Flowers::LargeTextRenderer.render error]: font cannot be a nullptr";
   ASSERT_THROW_WITH_MESSAGE(large_text_renderer.render(), std::runtime_error, expected_error_message);
}

TEST_F(Flowers_LargeTextRendererTest, render__returns_the_expected_response)
{
   ALLEGRO_FONT *font = al_create_builtin_font();
   Flowers::LargeTextRenderer large_text_renderer(font, "Hello Large Text!");

   al_clear_to_color(al_color_name("violet"));

   large_text_renderer.render();

   al_flip_display();
}

TEST_F(Flowers_LargeTextRendererTest, create_bitmap__with_a_nullptr_font_raises_an_exception)
{
   Flowers::LargeTextRenderer large_text_renderer;
   std::string expected_error_message = "[Flowers::LargeTextRenderer.create_bitmap error]: font cannot be a nullptr";
   ASSERT_THROW_WITH_MESSAGE(large_text_renderer.create_bitmap(), std::runtime_error, expected_error_message);
}

TEST_F(Flowers_LargeTextRendererTest, create_bitmap__returns_a_bitmap_with_the_rendered_text)
{
   ALLEGRO_FONT *font = al_create_builtin_font();
   Flowers::LargeTextRenderer large_text_renderer(font, "Hello Large Text!");

   al_clear_to_color(al_color_name("violet"));

   ALLEGRO_BITMAP *render = large_text_renderer.create_bitmap();
   al_draw_bitmap(render, 0, 0, 0);

   al_flip_display();

   //sleep(3);
}

