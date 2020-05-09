#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <AllegroFlare/Screen.hpp>
#include <allegro5/allegro.h>


namespace Flowers
{
   class TitleScreen : public AllegroFlare::Screen
   {
   private:
      AllegroFlare::FontBin* font_bin;

   public:
      TitleScreen(AllegroFlare::FontBin* font_bin=nullptr);
      ~TitleScreen();


   ALLEGRO_DISPLAY* infer_display();
   void draw_title();
   void key_down_func(ALLEGRO_EVENT* ev=nullptr) override;
   void primary_timer_func() override;
   };
}



