

#include <FlowersGame/ProgramRunner.hpp>
#include <iostream>
#include <AllegroFlare/FrameworkScreenRegistrar.hpp>
#include <Flowers/GameplayScreen.hpp>
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

Flowers::GameplayScreen gameplay_screen;
AllegroFlare::FrameworkScreenRegistrar registrar(&screens, &gameplay_screen);
registrar.append();

framework.run_loop();

registrar.remove();

return;

}
} // namespace FlowersGame


