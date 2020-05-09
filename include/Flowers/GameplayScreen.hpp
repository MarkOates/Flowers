#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <AllegroFlare/Screen.hpp>
#include <Flowers/Flower.hpp>
#include <Flowers/LargeTextScroller.hpp>
#include <Flowers/QuoteGenerator.hpp>
#include <allegro5/allegro.h>
#include <vector>


namespace Flowers
{
   class GameplayScreen : public AllegroFlare::Screen
   {
   private:
      AllegroFlare::FontBin* font_bin;
      std::vector<Flowers::Flower> flowers;
      std::vector<Flowers::LargeTextScroller> large_text_scrollers;
      int screen_width;
      int screen_height;
      int gameboard_width;
      int gameboard_height;
      Flowers::QuoteGenerator quote_generator;

   public:
      GameplayScreen(AllegroFlare::FontBin* font_bin=nullptr, int screen_width=1920, int screen_height=1080);
      ~GameplayScreen();


   void spawn_quote();
   void spawn_initial_flowers();
   void initialize();
   void key_down_func(ALLEGRO_EVENT* ev=nullptr) override;
   void primary_timer_func() override;
   };
}



