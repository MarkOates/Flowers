#pragma once


#include <AllegroFlare/Screen.hpp>
#include <string>


namespace Flowers
{
   class GameplayScreen : public AllegroFlare::Screen
   {
   private:

   public:
      GameplayScreen();
      ~GameplayScreen();


   std::string run();
   };
}



