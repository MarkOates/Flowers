#pragma once


#include <AllegroFlare/Framework.hpp>


namespace AllegroFlare
{
   class FrameworkScreenRegistrar
   {
   private:
      AllegroFlare::Framework* framework;
      AllegroFlare::Screens* screens;
      AllegroFlare::Screen* screen;

   public:
      FrameworkScreenRegistrar(AllegroFlare::Framework* framework=nullptr, AllegroFlare::Screens* screens=nullptr, AllegroFlare::Screen* screen=nullptr);
      ~FrameworkScreenRegistrar();


   bool append();
   bool remove();
   };
}



