

#include <Flowers/Flower.hpp>



namespace Flowers
{


Flower::Flower(ALLEGRO_COLOR color, float peduncle_height)
   : color(color)
   , peduncle_height(peduncle_height)
{
}


Flower::~Flower()
{
}


void Flower::set_color(ALLEGRO_COLOR color)
{
   this->color = color;
}


void Flower::set_peduncle_height(float peduncle_height)
{
   this->peduncle_height = peduncle_height;
}


ALLEGRO_COLOR Flower::get_color()
{
   return color;
}


float Flower::get_peduncle_height()
{
   return peduncle_height;
}


float Flower::calculate_receptacle_y()
{
return peduncle_height;
}
} // namespace Flowers


