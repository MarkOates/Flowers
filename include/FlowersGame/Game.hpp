#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Screen.hpp>
#include <allegro5/allegro.h>


namespace FlowersGame
{
   class Game : public AllegroFlare::Screen
   {
   private:
      AllegroFlare::Framework* framework;
      AllegroFlare::FontBin* font_bin;

   public:
      Game(AllegroFlare::Framework* framework=nullptr, AllegroFlare::FontBin* font_bin=nullptr);
      ~Game();


   ALLEGRO_DISPLAY* infer_display();
   void draw_press_enter_text();
   void draw_title();
   void key_down_func(ALLEGRO_EVENT* ev=nullptr) override;
   void primary_timer_func() override;
   };
}



