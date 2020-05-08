#pragma once


#include <allegro5/allegro.h>
#include <string>


namespace Flowers
{
   class LargeTextScroller
   {
   private:
      ALLEGRO_BITMAP* bitmap;
      float offset;
      float scroll_speed;
      bool finished;

   public:
      LargeTextScroller(ALLEGRO_BITMAP* bitmap=nullptr);
      ~LargeTextScroller();


      bool get_finished();
   void increment_by_step();
   std::string run();
   void draw();
   };
}



