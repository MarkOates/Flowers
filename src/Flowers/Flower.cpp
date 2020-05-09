

#include <Flowers/Flower.hpp>



namespace Flowers
{


Flower::Flower(ALLEGRO_COLOR color, float peduncle_height, float x, float y)
   : color(color)
   , peduncle_height(peduncle_height)
   , x(x)
   , y(y)
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


void Flower::set_x(float x)
{
   this->x = x;
}


void Flower::set_y(float y)
{
   this->y = y;
}


ALLEGRO_COLOR Flower::get_color()
{
   return color;
}


float Flower::get_peduncle_height()
{
   return peduncle_height;
}


float Flower::get_x()
{
   return x;
}


float Flower::get_y()
{
   return y;
}


float Flower::calculate_receptacle_y()
{
return peduncle_height;
}
} // namespace Flowers


