#pragma once


#include <string>
#include <vector>


namespace Flowers
{
   class QuoteGenerator
   {
   private:
      std::string filename;
      std::vector<std::string> quotes;

   public:
      QuoteGenerator();
      ~QuoteGenerator();


   std::string generate_quote();
   };
}



