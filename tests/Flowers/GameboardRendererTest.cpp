#include <gtest/gtest.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

#include <Flowers/GameboardRenderer.hpp>

TEST(Flowers_GameboardRendererTest, can_be_created_without_blowing_up)
{
   Flowers::GameboardRenderer gameboard_renderer;
}

TEST(Flowers_GameboardRendererTest, render__with_a_nullptr_gameboard_raises_an_exception)
{
   Flowers::GameboardRenderer gameboard_renderer(nullptr);
   std::string expected_error_message = "[Flowers::GameboardRenderer.render error]: gameboard cannot be a nullptr";
   ASSERT_THROW_WITH_MESSAGE(gameboard_renderer.render(), std::runtime_error, expected_error_message);
}

TEST(Flowers_GameboardRendererTest, render__renders_the_gameboard)
{
   al_init();
   al_init_primitives_addon();

   ALLEGRO_DISPLAY *display = al_create_display(1920, 1080);

   Flowers::Gameboard gameboard;
   gameboard.spawn_initial_flowers();

   Flowers::GameboardRenderer gameboard_renderer(&gameboard);
   gameboard_renderer.render();

   al_flip_display();

   sleep(2);

   al_uninstall_system();
}
