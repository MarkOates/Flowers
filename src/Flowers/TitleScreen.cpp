

#include <Flowers/TitleScreen.hpp>
#include <allegro5/allegro.h>


namespace Flowers
{


TitleScreen::TitleScreen()
   : AllegroFlare::Screen({})
{
}


TitleScreen::~TitleScreen()
{
}


void TitleScreen::primary_timer_func()
{
al_clear_to_color({0,0,0,0});
return;

}
} // namespace Flowers


