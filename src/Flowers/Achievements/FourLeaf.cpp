

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
}


void FourLeaf::on_achieved()
{
   if (!game) throw std::runtime_error("achievemnt failed");
   //std::cout << "You have achieved FourLeaf!" << std::endl;
   game->get_achieved().push_back("Four Leaf Clover"); // green, within a certain height, 4 petals
}


} // namespace Achievements
} // namespace Flowers


