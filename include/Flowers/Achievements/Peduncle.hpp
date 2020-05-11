#pragma once


#include <AllegroFlare/Achievement.hpp>
#include <FlowersGame/Game.hpp>
#include <string>


namespace Flowers
{
   namespace Achievements
   {
      class Peduncle : public AllegroFlare::Achievement
      {
      private:
         FlowersGame::Game* game;

      public:
         Peduncle(FlowersGame::Game* game=nullptr);
         ~Peduncle();


      std::string run();
      bool test_condition() override;
      void on_achieved() override;
      };
   }
}



