

#include <Flowers/LargeTextRenderer.hpp>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <stdexcept>
#include <sstream>
#include <allegro5/allegro.h>
#include <allegro_flare/render_cache.h>
#include <stdexcept>
#include <sstream>


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
if (!(font))
   {
      std::stringstream error_message;
      error_message << "LargeTextRenderer" << "::" << "render" << ": error: " << "guard \"font\" not met";
      throw std::runtime_error(error_message.str());
   }
ALLEGRO_COLOR font_fill_color = al_color_name("black");
al_draw_text(font, font_fill_color, 0, 0, ALLEGRO_ALIGN_LEFT, text.c_str());
return;

}

ALLEGRO_BITMAP* LargeTextRenderer::create_bitmap()
{
if (!(font))
   {
      std::stringstream error_message;
      error_message << "LargeTextRenderer" << "::" << "create_bitmap" << ": error: " << "guard \"font\" not met";
      throw std::runtime_error(error_message.str());
   }
allegro_flare::RenderCache render_cache;
int width = al_get_text_width(font, text.c_str());
int height = al_get_font_line_height(font);

render_cache.setup_surface(width, height, 0, 0);
render();
render_cache.finish_surface();

return render_cache.get_surface_bitmap();

}
} // namespace Flowers


