

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
return game->get_flower_of_interest().infer_has_dark_petals();

}

void DarkPetals::on_achieved()
{
game->get_achieved_ref().push_back("Dark Petals");
return;

}
} // namespace Achievements
} // namespace Flowers


