#pragma once


#include <Flowers/Gameboard.hpp>
#include <string>


namespace Flowers
{
   class GameboardRenderer
   {
   private:
      int gameboard_width;
      int gameboard_height;
      Flowers::Gameboard* gameboard;

   public:
      GameboardRenderer(Flowers::Gameboard* gameboard=nullptr);
      ~GameboardRenderer();


   void render();
   std::string run();
   };
}



