#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <Flowers/LargeTextScroller.hpp>
#include <Flowers/QuoteGenerator.hpp>
#include <string>
#include <vector>


namespace Flowers
{
   class QuoteSpawner
   {
   private:
      AllegroFlare::FontBin* font_bin;
      Flowers::QuoteGenerator quote_generator;
      std::vector<Flowers::LargeTextScroller> large_text_scrollers;

   public:
      QuoteSpawner(AllegroFlare::FontBin* font_bin=nullptr);
      ~QuoteSpawner();


   void spawn();
   void update();
   void draw();
   std::string run();
   };
}



