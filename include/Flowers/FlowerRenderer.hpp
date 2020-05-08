#pragma once


#include <Flowers/Flower.hpp>


namespace Flowers
{
   class FlowerRenderer
   {
   private:
      Flowers::Flower* flower;

   public:
      FlowerRenderer(Flowers::Flower* flower=nullptr);
      ~FlowerRenderer();


   void render();
   };
}



