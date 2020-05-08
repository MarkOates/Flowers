
#include <gtest/gtest.h>

#include <FlowersGame/ProgramRunner.hpp>

TEST(FlowersGame_ProgramRunnerTest, can_be_created_without_blowing_up)
{
   FlowersGame::ProgramRunner program_runner;
}

TEST(FlowersGame_ProgramRunnerTest, run__returns_the_expected_response)
{
   FlowersGame::ProgramRunner program_runner;
   std::string expected_string = "Hello World!";
   EXPECT_EQ(expected_string, program_runner.run());
}
