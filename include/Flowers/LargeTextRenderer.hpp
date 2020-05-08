#pragma once


#include <allegro5/allegro_font.h>
#include <string>


namespace Flowers
{
   class LargeTextRenderer
   {
   private:
      ALLEGRO_FONT* font;
      std::string text;

   public:
      LargeTextRenderer(ALLEGRO_FONT* font=nullptr, std::string text="");
      ~LargeTextRenderer();


   void render();
   };
}



