

#include <Flowers/QuoteGenerator.hpp>



namespace Flowers
{


QuoteGenerator::QuoteGenerator()
   : filename("data/content/quotes.txt")
   , quotes({})
{
}


QuoteGenerator::~QuoteGenerator()
{
}


std::string QuoteGenerator::generate_quote()
{
return "Hello World!";
}
} // namespace Flowers


