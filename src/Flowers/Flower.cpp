

#include <Flowers/Flower.hpp>



namespace Flowers
{


Flower::Flower(ALLEGRO_COLOR pistil_color, ALLEGRO_COLOR petal_color, float peduncle_height, float peduncle_thickness, float x, float y)
   : pistil_color(pistil_color)
   , petal_color(petal_color)
   , peduncle_height(peduncle_height)
   , peduncle_thickness(peduncle_thickness)
   , x(x)
   , y(y)
   , speed_sec(3.0)
   , created_at(0.0)
   , age(0.0)
   , num_petals(6)
   , lifespan(10.0)
   , spawned_offspring(false)
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


void Flower::set_peduncle_thickness(float peduncle_thickness)
{
   this->peduncle_thickness = peduncle_thickness;
}


void Flower::set_x(float x)
{
   this->x = x;
}


void Flower::set_y(float y)
{
   this->y = y;
}


void Flower::set_speed_sec(float speed_sec)
{
   this->speed_sec = speed_sec;
}


void Flower::set_created_at(float created_at)
{
   this->created_at = created_at;
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


void Flower::set_spawned_offspring(bool spawned_offspring)
{
   this->spawned_offspring = spawned_offspring;
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


float Flower::get_peduncle_thickness()
{
   return peduncle_thickness;
}


float Flower::get_x()
{
   return x;
}


float Flower::get_y()
{
   return y;
}


float Flower::get_speed_sec()
{
   return speed_sec;
}


float Flower::get_created_at()
{
   return created_at;
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


bool Flower::get_spawned_offspring()
{
   return spawned_offspring;
}


bool Flower::get_dead()
{
   return dead;
}


bool Flower::get_null_object()
{
   return null_object;
}


float &Flower::get_x_ref()
{
   return x;
}


float &Flower::get_y_ref()
{
   return y;
}


float Flower::calculate_receptacle_y()
{
return peduncle_height;
}

void Flower::set_peduncle_height(float peduncle_height)
{
if (peduncle_height <= 0) this->peduncle_height = 0;
else this->peduncle_height = peduncle_height;

}
} // namespace Flowers


