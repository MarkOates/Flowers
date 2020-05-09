#include <gtest/gtest.h>

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
   Flowers::GameboardRenderer gameboard_renderer;
   //EXPECT_EQ(expected_string, gameboard_renderer.render());
}
