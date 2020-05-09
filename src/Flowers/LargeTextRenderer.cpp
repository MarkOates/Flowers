

#include <Flowers/LargeTextRenderer.hpp>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro.h>
#include <allegro_flare/render_cache.h>


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

ALLEGRO_COLOR font_fill_color = al_color_name("pink");
al_draw_text(font, font_fill_color, 0, 0, ALLEGRO_ALIGN_LEFT, text.c_str());
return;

}

ALLEGRO_BITMAP* LargeTextRenderer::create_bitmap()
{
if (!font) throw std::runtime_error("[Flowers::LargeTextRenderer.create_bitmap error]: font cannot be a nullptr");

allegro_flare::RenderCache render_cache;
int width = al_get_text_width(font, text.c_str());
int height = al_get_font_line_height(font);

render_cache.setup_surface(width, height, 0, 0);
render();
render_cache.finish_surface();

return render_cache.get_surface_bitmap();

}
} // namespace Flowers


