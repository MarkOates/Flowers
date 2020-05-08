#pragma once


#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Screen.hpp>
#include <allegro5/allegro.h>


namespace FlowersGame
{
   class ApplicationController : public AllegroFlare::Screen
   {
   private:
      AllegroFlare::Framework* framework;

   public:
      ApplicationController();
      ~ApplicationController();


   void key_down_func(ALLEGRO_EVENT* ev=nullptr) override;
   void primary_timer_func() override;
   };
}



