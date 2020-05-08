
#include <gtest/gtest.h>

#define ASSERT_THROW_WITH_MESSAGE(code, raised_exception_type, raised_exception_message) \
   try { code; FAIL() << "Expected " # raised_exception_type; } \
   catch ( raised_exception_type const &err ) { EXPECT_EQ(err.what(), std::string( raised_exception_message )); } \
   catch (...) { FAIL() << "Expected " # raised_exception_type; }

#include <FlowersGame/ProgramRunner.hpp>

TEST(FlowersGame_ProgramRunnerTest, can_be_created_without_blowing_up)
{
   FlowersGame::ProgramRunner program_runner;
}

TEST(DISABLED_FlowersGame_ProgramRunnerTest, run__without_initialization_throws_an_error)
{
   FlowersGame::ProgramRunner program_runner;
   std::string expected_error_message = "[FlowersGame::ProgramRunner.run error]: must call initialize first";
   ASSERT_THROW_WITH_MESSAGE(program_runner.run(), std::runtime_error, expected_error_message);
   SUCCEED();
}

TEST(DISABLED_FlowersGame_ProgramRunnerTest, run__will_run_the_program)
{
   FlowersGame::ProgramRunner program_runner;
   program_runner.initialize();

   program_runner.run();
}

