#pragma once


#include <allegro5/allegro.h>
#include <string>


namespace Flowers
{
   class Flower
   {
   private:
      ALLEGRO_COLOR color;

   public:
      Flower(ALLEGRO_COLOR color={});
      ~Flower();

      void set_color(ALLEGRO_COLOR color);

      ALLEGRO_COLOR get_color();
   std::string run();
   };
}



