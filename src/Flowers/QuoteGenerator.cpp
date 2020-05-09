

#include <Flowers/QuoteGenerator.hpp>
#include <chrono>
#include <random>
#include <algorithm>


namespace Flowers
{


QuoteGenerator::QuoteGenerator()
   : quotes({})
{
}


QuoteGenerator::~QuoteGenerator()
{
}


void QuoteGenerator::shuffle()
{
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::shuffle(quotes.begin(), quotes.end(), std::default_random_engine(seed));

}

void QuoteGenerator::populate_quotes()
{
quotes = {
   { "The great thing about getting older is that you don't lose all the other ages you've been.", "Unknown" },
};

}

std::pair<std::string, std::string> QuoteGenerator::generate_quote()
{
if (quotes.empty()) { populate_quotes(); shuffle(); }
if (quotes.empty()) return { "no quotes", "" };
std::pair<std::string, std::string> quote_selection = quotes.back();
quotes.pop_back();
return quote_selection;

}
} // namespace Flowers


