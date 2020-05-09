#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Screen.hpp>
#include <AllegroFlare/Screens.hpp>
#include <allegro5/allegro.h>


namespace FlowersGame
{
   class ApplicationController : public AllegroFlare::Screen
   {
   private:
      AllegroFlare::Framework* framework;
      AllegroFlare::Screens* screens;
      AllegroFlare::FontBin* font_bin;

   public:
      ApplicationController(AllegroFlare::Framework* framework=nullptr, AllegroFlare::Screens* screens=nullptr, AllegroFlare::FontBin* font_bin=nullptr);
      ~ApplicationController();


   void create_gameplay_screen();
   void key_down_func(ALLEGRO_EVENT* ev=nullptr) override;
   };
}



