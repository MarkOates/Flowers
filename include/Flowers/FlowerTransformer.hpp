#pragma once


#include <Flowers/Flower.hpp>
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


   std::vector<Flowers::Flower> mutations();
   };
}



