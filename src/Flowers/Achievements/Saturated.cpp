

#include <Flowers/Achievements/Saturated.hpp>
#include <allegro5/allegro_color.h>


namespace Flowers
{
namespace Achievements
{


Saturated::Saturated(FlowersGame::Game* game)
   : AllegroFlare::Achievement({})
   , game(game)
{
}


Saturated::~Saturated()
{
}


bool Saturated::test_condition()
{
float saturation = game->get_flower_of_interest().calc_petal_color_saturation();
if (saturation > 0.6) return true;
return false;

}

void Saturated::on_achieved()
{
game->get_achieved_ref().push_back("Saturated Color");
return;

}
} // namespace Achievements
} // namespace Flowers


