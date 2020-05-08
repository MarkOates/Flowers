

#include <Flowers/LargeTextRenderer.hpp>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>


namespace Flowers
{


LargeTextRenderer::LargeTextRenderer(ALLEGRO_FONT* font, std::string text)
   : font(font)
   , text(text)
{
}


LargeTextRenderer::~LargeTextRenderer()
{
}


void LargeTextRenderer::render()
{
if (!font) throw std::runtime_error("[Flowers::LargeTextRenderer.render error]: font cannot be a nullptr");

ALLEGRO_COLOR fill_color = al_color_name("pink");
al_draw_text(font, fill_color, 0, 0, ALLEGRO_ALIGN_CENTER, text.c_str());
return;

}
} // namespace Flowers


