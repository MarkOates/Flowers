

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
float value = game->get_flower_of_interest().calc_petal_color_value();
if (value < 0.2f) return true;
return false;

}

void DarkPetals::on_achieved()
{
game->get_achieved_ref().push_back("Dark Petals");
return;

}
} // namespace Achievements
} // namespace Flowers


