#pragma once


#include <AllegroFlare/Achievement.hpp>
#include <FlowersGame/Game.hpp>


namespace Flowers
{
   namespace Achievements
   {
      class Fast : public AllegroFlare::Achievement
      {
      private:
         FlowersGame::Game* game;

      public:
         Fast(FlowersGame::Game* game=nullptr);
         ~Fast();


      bool test_condition() override;
      void on_achieved() override;
      };
   }
}



