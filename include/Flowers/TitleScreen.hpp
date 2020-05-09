#pragma once


#include <AllegroFlare/Screen.hpp>


namespace Flowers
{
   class TitleScreen : public AllegroFlare::Screen
   {
   private:

   public:
      TitleScreen();
      ~TitleScreen();


   void primary_timer_func() override;
   };
}



