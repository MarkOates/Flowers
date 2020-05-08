#pragma once


#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Screen.hpp>
#include <allegro5/allegro.h>


namespace Flowers
{
   class GameplayScreen : public AllegroFlare::Screen
   {
   private:
      AllegroFlare::Framework* framework;

   public:
      GameplayScreen();
      ~GameplayScreen();


   void key_down_func(ALLEGRO_EVENT* ev=nullptr) override;
   void primary_timer_func() override;
   };
}



