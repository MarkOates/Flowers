#pragma once


#include <AllegroFlare/Achievement.hpp>
#include <FlowersGame/Game.hpp>


namespace Flowers
{
   namespace Achievements
   {
      class Saturated : public AllegroFlare::Achievement
      {
      private:
         FlowersGame::Game* game;

      public:
         Saturated(FlowersGame::Game* game=nullptr);
         ~Saturated();


      bool test_condition() override;
      void on_achieved() override;
      };
   }
}



