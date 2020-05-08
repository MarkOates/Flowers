#pragma once


#include <allegro5/allegro.h>


namespace Flowers
{
   class Flower
   {
   private:
      ALLEGRO_COLOR color;
      float peduncle_height;

   public:
      Flower(ALLEGRO_COLOR color={}, float peduncle_height=5);
      ~Flower();

      void set_color(ALLEGRO_COLOR color);
      void set_peduncle_height(float peduncle_height);

      ALLEGRO_COLOR get_color();
      float get_peduncle_height();
   float calculate_receptacle_y();
   };
}



