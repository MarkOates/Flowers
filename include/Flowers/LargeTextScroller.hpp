#pragma once


#include <allegro5/allegro.h>


namespace Flowers
{
   class LargeTextScroller
   {
   private:
      ALLEGRO_BITMAP* bitmap;
      float scale;
      float scroll_speed;
      float offset;
      bool finished;

   public:
      LargeTextScroller(ALLEGRO_BITMAP* bitmap=nullptr, float scale=2.0f);
      ~LargeTextScroller();

      void set_scroll_speed(float scroll_speed);

      ALLEGRO_BITMAP* get_bitmap();
      bool get_finished();
   void increment_by_step();
   void draw();
   };
}



