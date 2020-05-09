

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

void ProgramRunner::destruct()
{
//if (initialized) framework.destruct();

}

void ProgramRunner::run()
{
initialize();

AllegroFlare::FontBin font_bin;
font_bin.set_full_path("/Users/markoates/Repos/Flowers/bin/programs/data/fonts");

FlowersGame::ApplicationController application_controller(&framework, &screens, &font_bin);
AllegroFlare::FrameworkScreenRegistrar registrar(&screens, &application_controller);
registrar.append();

application_controller.create_gameplay_screen();
framework.run_loop();

registrar.remove();

//destruct();

return;

}
} // namespace FlowersGame


