#pragma once


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

   public:
      ApplicationController(AllegroFlare::Framework* framework=nullptr, AllegroFlare::Screens* screens=nullptr);
      ~ApplicationController();


   void create_gameplay_screen();
   void key_down_func(ALLEGRO_EVENT* ev=nullptr) override;
   };
}



