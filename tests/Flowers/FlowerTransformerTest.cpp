
#include <gtest/gtest.h>

#include <Flowers/FlowerTransformer.hpp>

TEST(Flowers_FlowerTransformerTest, can_be_created_without_blowing_up)
{
   Flowers::FlowerTransformer flower_transformer;
}

TEST(Flowers_FlowerTransformerTest, mutations__returns_mutations_of_the_input_flower)
{
   Flowers::Flower flower;
   Flowers::FlowerTransformer flower_transformer(&flower);
   flower_transformer.mutations();
   SUCCEED();
}

#include <FlowersGame/ProgramRunner.hpp>

TEST(xGameRun, run_the_program)
{
   FlowersGame::ProgramRunner().run();
}

