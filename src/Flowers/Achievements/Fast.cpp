

#include <Flowers/Achievements/Fast.hpp>
#include <allegro5/allegro_color.h>


namespace Flowers
{
namespace Achievements
{


Fast::Fast(FlowersGame::Game* game)
   : AllegroFlare::Achievement({})
   , game(game)
{
}


Fast::~Fast()
{
}


bool Fast::test_condition()
{
return game->get_flower_of_interest().infer_is_fast();

}

void Fast::on_achieved()
{
game->get_achieved_ref().push_back("Fast Flower");
return;

}
} // namespace Achievements
} // namespace Flowers


