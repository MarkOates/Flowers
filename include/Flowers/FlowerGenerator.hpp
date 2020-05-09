#pragma once


#include <Flowers/Flower.hpp>
#include <allegro5/allegro.h>


namespace Flowers
{
   class FlowerGenerator
   {
   private:

   public:
      FlowerGenerator();
      ~FlowerGenerator();


   int random_int_incl(int min=0, int max=1);
   ALLEGRO_COLOR random_color();
   Flowers::Flower generate_null_flower();
   Flowers::Flower generate_random_flower();
   };
}



