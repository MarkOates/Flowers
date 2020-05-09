#pragma once


#include <Flowers/Flower.hpp>


namespace Flowers
{
   class FlowerUpdater
   {
   private:
      Flowers::Flower* flower;

   public:
      FlowerUpdater(Flowers::Flower* flower=nullptr);
      ~FlowerUpdater();


   void update();
   };
}



