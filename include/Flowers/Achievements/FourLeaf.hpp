#pragma once


#include <FlowersGame/Game.hpp>
#include <AllegroFlare/Achievement.hpp>


namespace Flowers
{
   namespace Achievements
   {
      class FourLeaf : public AllegroFlare::Achievement
      {
      private:
         FlowersGame::Game *game;

      public:
         FourLeaf(FlowersGame::Game *game);
         ~FourLeaf();

         bool virtual test_condition() override;
         void virtual on_achieved() override;
      };
   }
}



