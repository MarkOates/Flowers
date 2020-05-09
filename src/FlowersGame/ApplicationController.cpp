

#include <FlowersGame/ApplicationController.hpp>
#include <AllegroFlare/Screens.hpp>
#include <AllegroFlare/FrameworkScreenRegistrar.hpp>
#include <Flowers/GameplayScreen.hpp>


namespace FlowersGame
{


ApplicationController::ApplicationController(AllegroFlare::Framework* framework, AllegroFlare::Screens* screens)
   : AllegroFlare::Screen({})
   , framework(framework)
   , screens(screens)
{
}


ApplicationController::~ApplicationController()
{
}


void ApplicationController::create_gameplay_screen()
{
Flowers::GameplayScreen *gameplay_screen = new Flowers::GameplayScreen;
AllegroFlare::FrameworkScreenRegistrar(screens, gameplay_screen).append();
gameplay_screen->initialize();
return;

}

void ApplicationController::key_down_func(ALLEGRO_EVENT* ev)
{
if (!ev) return;
if (!framework)
{
   std::stringstream error_message;
   error_message << "FlowersGame::ApplicationController.key_down_func error: nullptr framework";
   throw std::runtime_error(error_message.str());
}
if (!screens) throw std::runtime_error("FlowersGame::ApplicationController.key_down_func error: nullptr screens");

switch(ev->keyboard.keycode)
{
case ALLEGRO_KEY_ESCAPE:
   framework->shutdown_program = true;
   break;
default:
   break;
}
return;

}
} // namespace FlowersGame


