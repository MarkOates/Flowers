#pragma once


#include <AllegroFlare/Achievement.hpp>
#include <FlowersGame/Game.hpp>


namespace Flowers
{
   namespace Achievements
   {
      class DarkPetals : public AllegroFlare::Achievement
      {
      private:
         FlowersGame::Game* game;

      public:
         DarkPetals(FlowersGame::Game* game=nullptr);
         ~DarkPetals();


      bool test_condition() override;
      void on_achieved() override;
      };
   }
}



