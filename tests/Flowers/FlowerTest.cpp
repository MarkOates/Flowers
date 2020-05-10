
#include <gtest/gtest.h>

#include <Flowers/Flower.hpp>

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

