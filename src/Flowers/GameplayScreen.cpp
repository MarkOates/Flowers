

#include <Flowers/GameplayScreen.hpp>



namespace Flowers
{


GameplayScreen::GameplayScreen()
   : AllegroFlare::Screen({})
   , framework(nullptr)
{
}


GameplayScreen::~GameplayScreen()
{
}


void GameplayScreen::key_down_func()
{
framework->shutdown_program = true;
return;

}

void GameplayScreen::primary_timer_func()
{
//al_clear_to_color("violet")
return;

}
} // namespace Flowers


