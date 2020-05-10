#pragma once


#include <AllegroFlare/Random.hpp>
#include <Flowers/Flower.hpp>
#include <vector>


namespace Flowers
{
   class FlowerTransformer
   {
   private:
      Flowers::Flower* source_flower;
      AllegroFlare::Random* random;

   public:
      FlowerTransformer(Flowers::Flower* source_flower=nullptr, AllegroFlare::Random* random=nullptr);
      ~FlowerTransformer();


   Flowers::Flower mutation();
   std::vector<Flowers::Flower> mutations();
   };
}



