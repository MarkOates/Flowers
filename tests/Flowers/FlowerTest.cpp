
#include <gtest/gtest.h>

#include <Flowers/Flower.hpp>

#include <allegro5/allegro_color.h>

TEST(Flowers_FlowerTest, can_be_created_without_blowing_up)
{
   Flowers::Flower flower;
}

TEST(Flowers_FlowerTest, dead__has_getter_and_is_set_to_false_by_default)
{
   Flowers::Flower flower;
   ASSERT_EQ(false, flower.get_dead());
}

TEST(Flowers_FlowerTest, set_peduncle_height__will_not_set_the_height_to_negative_values)
{
   Flowers::Flower flower;
   flower.set_peduncle_height(-1.0);
   ASSERT_EQ(0, flower.get_peduncle_height());
}

TEST(Flowers_FlowerTest, speed_sec__is_initialized_with_2)
{
   Flowers::Flower flower;
   ASSERT_EQ(3.0f, flower.get_speed_sec());
}

TEST(Flowers_FlowerTest, calc_petal_color_value__returns_the_value_of_the_petal_color)
{
   Flowers::Flower flower;
   flower.set_petal_color(al_color_name("black"));
   ASSERT_EQ(0.0, flower.calc_petal_color_value());
   flower.set_petal_color(al_color_name("white"));
   ASSERT_EQ(1.0, flower.calc_petal_color_value());
   flower.set_petal_color(al_color_name("gray"));
   //ASSERT_EQ(0.501961f, flower.calc_petal_color_value());
}

TEST(Flowers_FlowerTest, calc_petal_color_saturation__returns_the_saturation_of_the_petal_color)
{
   Flowers::Flower flower;
   flower.set_petal_color(al_color_name("black"));
   ASSERT_EQ(0.0, flower.calc_petal_color_saturation());
   flower.set_petal_color(al_color_name("white"));
   ASSERT_EQ(0.0, flower.calc_petal_color_saturation());
   flower.set_petal_color(al_color_name("red"));
   ASSERT_EQ(1.0, flower.calc_petal_color_saturation());
   flower.set_petal_color(al_color_name("aqua"));
   ASSERT_EQ(1.0, flower.calc_petal_color_saturation());
   flower.set_petal_color(al_color_name("violet"));
   //ASSERT_EQ(0.453781f, flower.calc_petal_color_saturation());
}

TEST(Flowers_FlowerTest, infer_has_dark_petals__returns_true_if_the_value_of_the_petal_is_less_than_0_45)
{
   Flowers::Flower flower;
   flower.set_petal_color(al_color_name("black"));
   ASSERT_EQ(true, flower.infer_has_dark_petals());
   flower.set_petal_color(al_color_name("midnightblue"));
   ASSERT_EQ(true, flower.infer_has_dark_petals());
   flower.set_petal_color(al_color_name("mediumblue"));
   ASSERT_EQ(false, flower.infer_has_dark_petals());
}

