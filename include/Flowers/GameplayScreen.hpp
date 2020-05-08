#pragma once


#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Screen.hpp>


namespace Flowers
{
   class GameplayScreen : public AllegroFlare::Screen
   {
   private:
      AllegroFlare::Framework* framework;

   public:
      GameplayScreen();
      ~GameplayScreen();


   void key_down_func() override;
   void primary_timer_func() override;
   };
}



