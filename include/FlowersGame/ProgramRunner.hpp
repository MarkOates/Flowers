#pragma once


#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Screens.hpp>


namespace FlowersGame
{
   class ProgramRunner
   {
   private:
      AllegroFlare::Screens screens;
      AllegroFlare::Framework framework;
      bool initialized;

   public:
      ProgramRunner();
      ~ProgramRunner();


   void initialize();
   void run();
   };
}



