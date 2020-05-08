

#include <FlowersGame/ApplicationController.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>


namespace FlowersGame
{


ApplicationController::ApplicationController()
   : AllegroFlare::Screen({})
   , framework(nullptr)
{
}


ApplicationController::~ApplicationController()
{
}


void ApplicationController::key_down_func(ALLEGRO_EVENT* ev)
{
if (!ev) return;

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

void ApplicationController::primary_timer_func()
{
al_clear_to_color(al_color_name("violet"));

return;

}
} // namespace FlowersGame


