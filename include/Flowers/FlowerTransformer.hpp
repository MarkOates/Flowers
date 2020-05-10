#pragma once


#include <Flowers/Flower.hpp>
#include <allegro5/allegro.h>
#include <vector>


namespace Flowers
{
   class FlowerTransformer
   {
   private:
      Flowers::Flower* source_flower;

   public:
      FlowerTransformer(Flowers::Flower* source_flower=nullptr);
      ~FlowerTransformer();


   int random_int_incl(int min=0, int max=1);
   float random_float_incl(int min=0, int max=1);
   ALLEGRO_COLOR random_color();
   Flowers::Flower mutation();
   std::vector<Flowers::Flower> mutations();
   };
}



