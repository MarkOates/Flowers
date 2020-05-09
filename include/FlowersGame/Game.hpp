#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Screen.hpp>
#include <Flowers/Flower.hpp>
#include <allegro5/allegro.h>
#include <string>


namespace FlowersGame
{
   class Game : public AllegroFlare::Screen
   {
   private:
      AllegroFlare::Framework* framework;
      AllegroFlare::FontBin* font_bin;
      bool showing_title;
      Flowers::Flower flower_of_interest;
      std::string state;

   public:
      Game(AllegroFlare::Framework* framework=nullptr, AllegroFlare::FontBin* font_bin=nullptr);
      ~Game();


   ALLEGRO_DISPLAY* infer_display();
   void draw_press_enter_text();
   void start_game();
   void draw_title();
   void draw_gameplay();
   void key_down_func(ALLEGRO_EVENT* ev=nullptr) override;
   void primary_timer_func() override;
   };
}



