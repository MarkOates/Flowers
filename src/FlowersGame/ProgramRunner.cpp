

#include <FlowersGame/ProgramRunner.hpp>
#include <iostream>
#include <AllegroFlare/FrameworkScreenRegistrar.hpp>
#include <FlowersGame/ApplicationController.hpp>
#include <AllegroFlare/Display.hpp>


namespace FlowersGame
{


ProgramRunner::ProgramRunner()
   : screens({})
   , framework(screens)
   , display(nullptr)
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
display = framework.create_display(1920, 1080);
initialized = true;
return;

}

void ProgramRunner::run()
{
initialize();

FlowersGame::ApplicationController application_controller;
AllegroFlare::FrameworkScreenRegistrar registrar(&screens, &application_controller);
registrar.append();

framework.run_loop();

registrar.remove();

return;

}
} // namespace FlowersGame


