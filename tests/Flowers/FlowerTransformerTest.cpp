
#include <gtest/gtest.h>

#include <Flowers/FlowerTransformer.hpp>

TEST(Flowers_FlowerTransformerTest, can_be_created_without_blowing_up)
{
   Flowers::FlowerTransformer flower_transformer;
}

TEST(Flowers_FlowerTransformerTest, mutations__returns_mutations_of_the_input_flower)
{
   Flowers::FlowerTransformer flower_transformer;
   flower_transformer.mutations();
   SUCCEED();
}
