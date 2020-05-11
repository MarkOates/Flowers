#pragma once


#include <Flowers/Flower.hpp>
#include <allegro5/allegro.h>


namespace Flowers
{
   class FlowerRenderer
   {
   private:
      Flowers::Flower* flower;
      bool render_timer;
      float outline_thickness;
      ALLEGRO_COLOR outline_color;
      float TAU;

   public:
      FlowerRenderer(Flowers::Flower* flower=nullptr, bool render_timer=false);
      ~FlowerRenderer();


   void render_time_arc();
   void render_petals();
   void render_pistil();
   void render_peduncle();
   void render_null_flower();
   void render();
   };
}



