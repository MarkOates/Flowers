#pragma once


#include <AllegroFlare/Achievement.hpp>
#include <FlowersGame/Game.hpp>


namespace Flowers
{
   namespace Achievements
   {
      class BlackPetals : public AllegroFlare::Achievement
      {
      private:
         FlowersGame::Game* game;

      public:
         BlackPetals(FlowersGame::Game* game=nullptr);
         ~BlackPetals();


      bool test_condition() override;
      void on_achieved() override;
      };
   }
}



