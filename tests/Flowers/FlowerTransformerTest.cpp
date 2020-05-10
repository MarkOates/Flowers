
#include <gtest/gtest.h>

#include <Flowers/FlowerTransformer.hpp>

TEST(Flowers_FlowerTransformerTest, can_be_created_without_blowing_up)
{
   Flowers::FlowerTransformer flower_transformer;
}

TEST(Flowers_FlowerTransformerTest, mutations__returns_mutations_of_the_input_flower)
{
   al_init();

   AllegroFlare::Random random(1234);

   Flowers::Flower flower;
   Flowers::FlowerTransformer flower_transformer(&flower, &random);
   flower_transformer.mutations();
   al_uninstall_system();

   SUCCEED();
}

#include <FlowersGame/ProgramRunner.hpp>

TEST(xGameRun, run_the_program)
{
   FlowersGame::ProgramRunner().run();
}

