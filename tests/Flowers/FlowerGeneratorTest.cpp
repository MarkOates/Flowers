#include <gtest/gtest.h>

#include <Flowers/FlowerGenerator.hpp>

TEST(Flowers_FlowerGeneratorTest, can_be_created_without_blowing_up)
{
   Flowers::FlowerGenerator flower_generator;
}

TEST(Flowers_FlowerGeneratorTest, generate_random_flower__creates_flowers_with_random_values)
{
   Flowers::FlowerGenerator flower_generator;
}

