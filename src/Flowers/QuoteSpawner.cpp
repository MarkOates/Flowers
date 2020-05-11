

#include <Flowers/QuoteSpawner.hpp>
#include <Flowers/LargeTextRenderer.hpp>
#include <stdexcept>
#include <sstream>
#include <sstream>
#include <stdexcept>
#include <sstream>


namespace Flowers
{


QuoteSpawner::QuoteSpawner(AllegroFlare::FontBin* font_bin)
   : font_bin(font_bin)
   , quote_generator()
   , large_text_scrollers({})
{
}


QuoteSpawner::~QuoteSpawner()
{
}


void QuoteSpawner::spawn()
{
if (!(font_bin))
   {
      std::stringstream error_message;
      error_message << "QuoteSpawner" << "::" << "spawn" << ": error: " << "guard \"font_bin\" not met";
      throw std::runtime_error(error_message.str());
   }
ALLEGRO_FONT *font = font_bin->operator[]("Poly-Italic.otf 16");
Flowers::LargeTextRenderer renderer(font, quote_generator.generate_quote().first);
ALLEGRO_BITMAP *bitmap = renderer.create_bitmap();
Flowers::LargeTextScroller scroller(bitmap);
large_text_scrollers.push_back(scroller);

}

void QuoteSpawner::update()
{
if (!(font_bin))
   {
      std::stringstream error_message;
      error_message << "QuoteSpawner" << "::" << "update" << ": error: " << "guard \"font_bin\" not met";
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


