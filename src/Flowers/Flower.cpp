

#include <Flowers/Flower.hpp>



namespace Flowers
{


Flower::Flower(ALLEGRO_COLOR pistil_color, ALLEGRO_COLOR petal_color, float peduncle_height, float x, float y)
   : pistil_color(pistil_color)
   , petal_color(petal_color)
   , peduncle_height(peduncle_height)
   , x(x)
   , y(y)
   , age(0.0)
   , num_petals(6)
   , lifespan(10.0)
   , dead(false)
   , null_object(false)
{
}


Flower::~Flower()
{
}


void Flower::set_pistil_color(ALLEGRO_COLOR pistil_color)
{
   this->pistil_color = pistil_color;
}


void Flower::set_petal_color(ALLEGRO_COLOR petal_color)
{
   this->petal_color = petal_color;
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


void Flower::set_num_petals(int num_petals)
{
   this->num_petals = num_petals;
}


void Flower::set_lifespan(float lifespan)
{
   this->lifespan = lifespan;
}


void Flower::set_dead(bool dead)
{
   this->dead = dead;
}


void Flower::set_null_object(bool null_object)
{
   this->null_object = null_object;
}


ALLEGRO_COLOR Flower::get_pistil_color()
{
   return pistil_color;
}


ALLEGRO_COLOR Flower::get_petal_color()
{
   return petal_color;
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


int Flower::get_num_petals()
{
   return num_petals;
}


float Flower::get_lifespan()
{
   return lifespan;
}


bool Flower::get_dead()
{
   return dead;
}


bool Flower::get_null_object()
{
   return null_object;
}


float Flower::calculate_receptacle_y()
{
return peduncle_height;
}
} // namespace Flowers


