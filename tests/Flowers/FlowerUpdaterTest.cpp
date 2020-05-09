
#include <gtest/gtest.h>

#include <Flowers/FlowerUpdater.hpp>

TEST(Flowers_FlowerUpdaterTest, can_be_created_without_blowing_up)
{
   Flowers::FlowerUpdater flower_updater;
}

TEST(Flowers_FlowerUpdaterTest, update__will_update_the_flower)
{
   Flowers::Flower flower;
   Flowers::FlowerUpdater flower_updater(&flower);

   flower_updater.update();

   SUCCEED();
}

TEST(Flowers_FlowerUpdaterTest, update__when_the_age_is_greater_than_the_lifespan_will_mark_as_dead)
{
   Flowers::Flower flower;
   flower.set_lifespan(100.0f);
   flower.set_age(101.0f);

   Flowers::FlowerUpdater flower_updater(&flower);

   flower_updater.update();

   ASSERT_EQ(true, flower.get_dead());

   SUCCEED();
}

