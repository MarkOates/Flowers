

#include <Flowers/Achievements/Peduncle.hpp>



namespace Flowers
{
namespace Achievements
{


Peduncle::Peduncle(FlowersGame::Game* game)
   : AllegroFlare::Achievement({})
   , game(game)
{
}


Peduncle::~Peduncle()
{
}


std::string Peduncle::run()
{
return "Hello World!";
}

bool Peduncle::test_condition()
{
if (game->get_flower_of_interest().get_peduncle_height() > 30) return true;
return false;

}

void Peduncle::on_achieved()
{
game->get_achieved_ref().push_back("Little Stem");
return;

}
} // namespace Achievements
} // namespace Flowers


