#pragma once


#include <Flowers/Flower.hpp>
#include <vector>


namespace Flowers
{
   class FlowerTransformer
   {
   private:

   public:
      FlowerTransformer();
      ~FlowerTransformer();


   std::vector<Flowers::Flower> mutations();
   };
}



