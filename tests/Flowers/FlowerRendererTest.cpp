
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

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


TEST_F(Flowers_FlowerRendererTest, render__with_a_nullptr_flower_raises_an_exception)
{
   std::string expected_error_message = "[Flower::FlowerRenderer.render() error]: You must pass a valid flower";
   Flowers::FlowerRenderer flower_renderer;
   ASSERT_THROW_WITH_MESSAGE(flower_renderer.render(), std::runtime_error, expected_error_message);
}


TEST_F(Flowers_FlowerRendererTest, render__returns_the_expected_response)
{
   Flowers::Flower flower;
   Flowers::FlowerRenderer flower_renderer(&flower);

   al_clear_to_color(al_color_name("pink"));
   flower_renderer.render();

   al_flip_display();

   sleep(2);
}

