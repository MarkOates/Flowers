

#include <Flowers/Flower.hpp>



namespace Flowers
{


Flower::Flower(ALLEGRO_COLOR pistil_color, float peduncle_height, float x, float y)
   : pistil_color(pistil_color)
   , peduncle_height(peduncle_height)
   , x(x)
   , y(y)
   , age(0.0)
   , lifespan(10.0)
   , dead(false)
{
}


Flower::~Flower()
{
}


void Flower::set_pistil_color(ALLEGRO_COLOR pistil_color)
{
   this->pistil_color = pistil_color;
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


void Flower::set_age(float age)
{
   this->age = age;
}


void Flower::set_lifespan(float lifespan)
{
   this->lifespan = lifespan;
}


void Flower::set_dead(bool dead)
{
   this->dead = dead;
}


ALLEGRO_COLOR Flower::get_pistil_color()
{
   return pistil_color;
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


float Flower::get_age()
{
   return age;
}


float Flower::get_lifespan()
{
   return lifespan;
}


bool Flower::get_dead()
{
   return dead;
}


float Flower::calculate_receptacle_y()
{
return peduncle_height;
}
} // namespace Flowers


