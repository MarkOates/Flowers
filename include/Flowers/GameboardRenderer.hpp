#pragma once


#include <Flowers/Gameboard.hpp>
#include <string>


namespace Flowers
{
   class GameboardRenderer
   {
   private:
      Flowers::Gameboard* gameboard;

   public:
      GameboardRenderer(Flowers::Gameboard* gameboard=nullptr);
      ~GameboardRenderer();


   void draw_cursor();
   void render();
   std::string run();
   };
}



