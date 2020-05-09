#pragma once


#include <allegro5/allegro.h>


namespace Flowers
{
   class Flower
   {
   private:
      ALLEGRO_COLOR color;
      float peduncle_height;
      float x;
      float y;
      float age;
      float lifespan;
      bool dead;

   public:
      Flower(ALLEGRO_COLOR color={}, float peduncle_height=5, float x=0, float y=0);
      ~Flower();

      void set_color(ALLEGRO_COLOR color);
      void set_peduncle_height(float peduncle_height);
      void set_x(float x);
      void set_y(float y);
      void set_age(float age);
      void set_lifespan(float lifespan);
      void set_dead(bool dead);

      ALLEGRO_COLOR get_color();
      float get_peduncle_height();
      float get_x();
      float get_y();
      float get_age();
      float get_lifespan();
      bool get_dead();
   float calculate_receptacle_y();
   };
}



