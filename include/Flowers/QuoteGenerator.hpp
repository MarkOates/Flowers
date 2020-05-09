#pragma once


#include <string>
#include <utility>
#include <vector>


namespace Flowers
{
   class QuoteGenerator
   {
   private:
      std::vector<std::pair<std::string, std::string>> quotes;

   public:
      QuoteGenerator();
      ~QuoteGenerator();


   void shuffle();
   void populate_quotes();
   std::pair<std::string, std::string> generate_quote();
   };
}



