

#include <FlowersGame/ProgramRunner.hpp>
#include <iostream>
#include <AllegroFlare/FrameworkScreenRegistrar.hpp>
#include <FlowersGame/Game.hpp>
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
if (initialized) framework.destruct();

}

void ProgramRunner::run()
{
initialize();

AllegroFlare::FontBin font_bin;
font_bin.set_full_path("/Users/markoates/Repos/Flowers/bin/programs/data/fonts");

AllegroFlare::Motion motion;

FlowersGame::Game game(&framework, &font_bin, &framework.motion());
game.load_achievements(); // hack
AllegroFlare::FrameworkScreenRegistrar registrar(&screens, &game);
registrar.append();

framework.run_loop();

registrar.remove();


//destruct();

return;

}
} // namespace FlowersGame


