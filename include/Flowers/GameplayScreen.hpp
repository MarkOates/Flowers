#pragma once


#include <AllegroFlare/Screen.hpp>


namespace Flowers
{
   class GameplayScreen : public AllegroFlare::Screen
   {
   private:

   public:
      GameplayScreen();
      ~GameplayScreen();


   void primary_timer_func() override;
   };
}



