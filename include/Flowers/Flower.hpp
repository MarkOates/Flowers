#pragma once


#include <allegro5/allegro.h>


namespace Flowers
{
   class Flower
   {
   private:
      ALLEGRO_COLOR pistil_color;
      ALLEGRO_COLOR petal_color;
      float peduncle_height;
      float peduncle_thickness;
      float x;
      float y;
      float speed_sec;
      float age;
      int num_petals;
      float lifespan;
      bool dead;
      bool null_object;

   public:
      Flower(ALLEGRO_COLOR pistil_color={1.0,1.0,1.0,1.0}, ALLEGRO_COLOR petal_color={1.0,1.0,1.0,1.0}, float peduncle_height=5, float peduncle_thickness=3.0f, float x=0, float y=0);
      ~Flower();

      void set_pistil_color(ALLEGRO_COLOR pistil_color);
      void set_petal_color(ALLEGRO_COLOR petal_color);
      void set_peduncle_thickness(float peduncle_thickness);
      void set_x(float x);
      void set_y(float y);
      void set_speed_sec(float speed_sec);
      void set_age(float age);
      void set_num_petals(int num_petals);
      void set_lifespan(float lifespan);
      void set_dead(bool dead);
      void set_null_object(bool null_object);

      ALLEGRO_COLOR get_pistil_color();
      ALLEGRO_COLOR get_petal_color();
      float get_peduncle_height();
      float get_peduncle_thickness();
      float get_x();
      float get_y();
      float get_speed_sec();
      float get_age();
      int get_num_petals();
      float get_lifespan();
      bool get_dead();
      bool get_null_object();
      float &get_x_ref();
      float &get_y_ref();
   float calculate_receptacle_y();
   void set_peduncle_height(float peduncle_height=5);
   };
}



