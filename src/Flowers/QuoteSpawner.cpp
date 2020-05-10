

#include <Flowers/QuoteSpawner.hpp>
#include <sstream>


namespace Flowers
{


QuoteSpawner::QuoteSpawner()
   : font_bin(nullptr)
   , quote_generator()
   , large_text_scrollers({})
{
}


QuoteSpawner::~QuoteSpawner()
{
}


void QuoteSpawner::update()
{
if (!(font_bin))
{
   std::stringstream error_message;
   error_message << "QuoteSpawner" << "::" << "update" << ": error: " << "guard not met";
   throw std::runtime_error(error_message.str());
}
for (auto &large_text_scroller : large_text_scrollers)
{
   large_text_scroller.increment_by_step();
}
return;

}

void QuoteSpawner::draw()
{
for (auto &large_text_scroller : large_text_scrollers)
{
   large_text_scroller.draw();
}
return;

}

std::string QuoteSpawner::run()
{
return "Hello World!";
}
} // namespace Flowers


