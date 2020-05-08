#pragma once


#include <Flowers/Flower.hpp>
#include <allegro5/allegro.h>


namespace Flowers
{
   class FlowerRenderer
   {
   private:
      Flowers::Flower* flower;
      float outline_thickness;
      ALLEGRO_COLOR outline_color;

   public:
      FlowerRenderer(Flowers::Flower* flower=nullptr);
      ~FlowerRenderer();


   void render_pistil();
   void render_peduncle();
   void render();
   };
}



