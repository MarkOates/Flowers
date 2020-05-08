
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

#include <Flowers/FlowerRenderer.hpp>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <allegro_flare/placement2d.h>

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
};


#include <allegro5/allegro_color.h>


TEST_F(Flowers_FlowerRendererTest, DISABLED_can_be_created_without_blowing_up)
{
   Flowers::FlowerRenderer flower_renderer;
}


TEST_F(Flowers_FlowerRendererTest, render__with_a_nullptr_flower_raises_an_exception)
{
   al_init_primitives_addon();

   std::string expected_error_message = "[Flower::FlowerRenderer.render() error]: You must pass a valid flower";
   Flowers::FlowerRenderer flower_renderer;
   ASSERT_THROW_WITH_MESSAGE(flower_renderer.render(), std::runtime_error, expected_error_message);
}


//TEST_F(Flowers_FlowerRendererTest, render__without_initialization_of_the_primitives_addon_raises_an_exception)
//{
//   std::string expected_error_message =
//      "[Flower::FlowerRenderer.render() error]: You must al_init_primitives_addon()";
//   Flowers::FlowerRenderer flower_renderer;
//   ASSERT_THROW_WITH_MESSAGE(flower_renderer.render(), std::runtime_error, expected_error_message);
//}


TEST_F(Flowers_FlowerRendererTest, render__renders_a_flower_with_default_values)
{
   Flowers::Flower flower;
   Flowers::FlowerRenderer flower_renderer(&flower);

   allegro_flare::placement2d place(al_get_display_width(display)/2, al_get_display_height(display)/2, 0, 0);
   place.start_transform();

   al_clear_to_color(al_color_name("pink"));
   flower_renderer.render();

   place.restore_transform();

   al_flip_display();

   //sleep(2);
}


TEST_F(Flowers_FlowerRendererTest, render__renders_a_flower_with_color)
{
   Flowers::Flower flower(al_color_name("aqua"), 40);
   Flowers::FlowerRenderer flower_renderer(&flower);

   allegro_flare::placement2d place(al_get_display_width(display)/2, al_get_display_height(display)/2, 0, 0);
   place.start_transform();

   al_clear_to_color(al_color_name("pink"));
   flower_renderer.render();

   place.restore_transform();

   al_flip_display();

   //sleep(2);
}

