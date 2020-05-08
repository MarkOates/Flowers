
#include <gtest/gtest.h>

#include <FlowersGame/ProgramRunner.hpp>

TEST(FlowersGame_ProgramRunnerTest, can_be_created_without_blowing_up)
{
   FlowersGame::ProgramRunner program_runner;
}

TEST(DISABLED_FlowersGame_ProgramRunnerTest, run__runs_the_program)
{
   FlowersGame::ProgramRunner program_runner;
   program_runner.run();
   SUCCEED();
}
