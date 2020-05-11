
#include <gtest/gtest.h>

#include <Flowers/FlowerTransformer.hpp>

static void EXPECT_EQ_COLOR(ALLEGRO_COLOR expected, ALLEGRO_COLOR actual)
{
   EXPECT_EQ(expected.r, actual.r);
   EXPECT_EQ(expected.g, actual.g);
   EXPECT_EQ(expected.b, actual.b);
   EXPECT_EQ(expected.a, actual.a);
}

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
   std::vector<Flowers::Flower> mutations = flower_transformer.mutations();

   for (auto &mutation : mutations)
   {
      //EXPECT_EQ_COLOR(flower.get_petal_color(), mutation.get_petal_color());
   }

   al_uninstall_system();

   SUCCEED();
}

#include <FlowersGame/ProgramRunner.hpp>

TEST(xGameRun, run_the_program)
{
   FlowersGame::ProgramRunner().run();
}

