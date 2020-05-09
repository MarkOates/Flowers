

#include <Flowers/FlowerUpdater.hpp>
#include <stdexcept>


namespace Flowers
{


FlowerUpdater::FlowerUpdater(Flowers::Flower* flower)
   : flower(flower)
{
}


FlowerUpdater::~FlowerUpdater()
{
}


void FlowerUpdater::update()
{
if (!flower) throw std::runtime_error("[Flower::FlowerUpdater.update() error]: You must pass a valid flower");

float flower_age = flower->get_age();
float flower_lifespan = flower->get_lifespan();
if (flower_age > flower_lifespan)
{
   flower->set_dead(true);
}
return;

}
} // namespace Flowers


