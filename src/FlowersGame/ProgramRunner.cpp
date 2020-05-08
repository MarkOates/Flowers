

#include <FlowersGame/ProgramRunner.hpp>
#include <iostream>


namespace FlowersGame
{


ProgramRunner::ProgramRunner()
   : screens({})
   , framework(screens)
   , initialized(false)
{
}


ProgramRunner::~ProgramRunner()
{
}


void ProgramRunner::initialize()
{
if (initialized) return;
framework.initialize();
initialized = true;
return;

}

void ProgramRunner::run()
{
if (!initialized) throw std::runtime_error("[FlowersGame::ProgramRunner.run error]: must call initialize first");
std::cout << "Hello, Flowers!" << std::endl;

return;

}
} // namespace FlowersGame


