

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
ALLEGRO_COLOR color = game->get_flower_of_interest().get_petal_color();
float h, s, l;
al_color_rgb_to_hsl(color.r, color.g, color.b, &h, &s, &l);
if (s > 0.7) return true;
return false;

}

void Saturated::on_achieved()
{
game->get_achieved_ref().push_back("Saturated Color");
return;

}
} // namespace Achievements
} // namespace Flowers


