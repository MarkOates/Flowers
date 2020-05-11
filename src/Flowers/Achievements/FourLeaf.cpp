

#include <Flowers/Achievements/FourLeaf.hpp>


#include <iostream>

namespace Flowers
{
namespace Achievements
{


FourLeaf::FourLeaf(FlowersGame::Game *game)
   : game(game)
{
}


FourLeaf::~FourLeaf()
{
}


bool FourLeaf::test_condition()
{
   if (!game) return false;
   if (game->get_flower_of_interest().get_num_petals() == 4) return true;
   return false;
}


void FourLeaf::on_achieved()
{
   if (!game) throw std::runtime_error("achievemnt processing failed");
   game->get_achieved_ref().push_back("Four Leaf"); // green, within a certain height, 4 petals
}


} // namespace Achievements
} // namespace Flowers


