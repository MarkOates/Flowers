

#include <Flowers/Flower.hpp>



namespace Flowers
{


Flower::Flower(ALLEGRO_COLOR color)
   : color(color)
{
}


Flower::~Flower()
{
}


void Flower::set_color(ALLEGRO_COLOR color)
{
   this->color = color;
}


ALLEGRO_COLOR Flower::get_color()
{
   return color;
}


std::string Flower::run()
{
return "Hello World!";
}
} // namespace Flowers


