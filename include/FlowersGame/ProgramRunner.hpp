#pragma once


#include <AllegroFlare/Display.hpp>
#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Screens.hpp>


namespace FlowersGame
{
   class ProgramRunner
   {
   private:
      AllegroFlare::Screens screens;
      AllegroFlare::Framework framework;
      AllegroFlare::Display* display;
      bool initialized;

   public:
      ProgramRunner();
      ~ProgramRunner();


   void initialize();
   void destruct();
   void run();
   };
}



