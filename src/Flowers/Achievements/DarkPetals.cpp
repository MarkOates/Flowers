

#include <Flowers/Achievements/DarkPetals.hpp>
#include <allegro5/allegro_color.h>


namespace Flowers
{
namespace Achievements
{


DarkPetals::DarkPetals(FlowersGame::Game* game)
   : AllegroFlare::Achievement({})
   , game(game)
{
}


DarkPetals::~DarkPetals()
{
}


bool DarkPetals::test_condition()
{
ALLEGRO_COLOR color = game->get_flower_of_interest().get_petal_color();
float h, s, v;
al_color_rgb_to_hsv(color.r, color.g, color.b, &h, &s, &v);
if (v < 0.2f) return true;
return false;

}

void DarkPetals::on_achieved()
{
game->get_achieved_ref().push_back("Dark Petals");
return;

}
} // namespace Achievements
} // namespace Flowers


