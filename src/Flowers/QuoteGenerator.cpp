

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
   {
      "The great thing about getting older is that you don't lose all the other ages you've been.",
      "Unknown",
   },
   { "The good thing about getting older is that, as you become less attractive, you have less desire " \
        "to go out and conquer everyone you see.",
      "Unknown",
   },
   {
      "I can honestly say I love getting older. Then again, I never put my glasses on before looking " \
         "in the mirror.",
      "Unknown",
   },
   {
      "As I started getting older, I realized, \"I'm so happy!\" I didn't expect this! I wasn't happy when I was young.",
      "Unknown",
   },
   {
      "Let us never know what old age is. Let us know the happiness time brings, not count the years.",
      "Unknown",
   },
   {
      "I was thinking about how people seem to read the bible a lot more as they get older, and then it dawned on me - they're cramming for their final exam.",
      "George Carlin"
   },
   {
      "O, elixir of youth, thy name is hair dye.",
      "Unknown",
   },
   {
      "The longer I live the more beautiful life becomes",
      "Unknown",
   },
   {
      "Age is no barrier. It's a limitation you put on your mind.",
      "Unknown",
   },
   {
      "You don't stop laughing when you grow old, you grow old when you stop laughing.",
      "Unknown",
   },
   {
      "Grow old along with me! The best is yet to be.",
      "Unknown",
   },
   {
      "Aging is not lost youth but a new stage of opportunity and strength.",
      "Unknown",
   },
   {
      "With age comes the inner, the higher life. Who would be forever young, to dwell always in externals?",
      "Unknown",
   },
   {
      "We don't grow older, we grow riper.",
      "Unknown",
   },
   {
      "We don't stop playing because we grow old. We grow old because we stop playing.",
      "Unknown",
   },
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


