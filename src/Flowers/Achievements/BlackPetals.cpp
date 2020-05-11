

#include <Flowers/Achievements/BlackPetals.hpp>
#include <allegro5/allegro_color.h>


namespace Flowers
{
namespace Achievements
{


BlackPetals::BlackPetals(FlowersGame::Game* game)
   : AllegroFlare::Achievement({})
   , game(game)
{
}


BlackPetals::~BlackPetals()
{
}


bool BlackPetals::test_condition()
{
return game->get_flower_of_interest().has_black_petals();

}

void BlackPetals::on_achieved()
{
game->get_achieved_ref().push_back("Black Flower");
return;

}
} // namespace Achievements
} // namespace Flowers


