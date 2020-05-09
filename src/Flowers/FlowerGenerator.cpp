

#include <Flowers/FlowerGenerator.hpp>
#include <allegro5/allegro.h>


namespace Flowers
{


FlowerGenerator::FlowerGenerator()
{
}


FlowerGenerator::~FlowerGenerator()
{
}


int FlowerGenerator::random_int_incl(int min, int max)
{
return rand()%(max-min+1) + min;

}

ALLEGRO_COLOR FlowerGenerator::random_color()
{
return al_map_rgb(random_int_incl(0, 255), random_int_incl(0, 255), random_int_incl(0, 255));

}

Flowers::Flower FlowerGenerator::generate_random_flower()
{
return Flowers::Flower{};

}
} // namespace Flowers


