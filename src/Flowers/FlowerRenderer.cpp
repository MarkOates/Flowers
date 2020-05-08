

#include <Flowers/FlowerRenderer.hpp>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>


namespace Flowers
{


FlowerRenderer::FlowerRenderer(Flowers::Flower* flower)
   : flower(flower)
{
}


FlowerRenderer::~FlowerRenderer()
{
}


void FlowerRenderer::render()
{
if (!flower) throw std::runtime_error("[Flower::FlowerRenderer.render() error]: You must pass a valid flower");
//if (!al_is_primitives_addon_initialized())
//   throw std::runtime_error("[Flower::FlowerRenderer.render() error]: You must al_init_primitives_addon()");

ALLEGRO_COLOR outline_color = al_color_name("purple");
float outline_thickness = 4.0f;
ALLEGRO_COLOR color = flower->get_color();
float stigma_radius = 10.0f;
al_draw_filled_circle(0, 0, stigma_radius, color);
al_draw_circle(0, 0, stigma_radius, outline_color, outline_thickness);

return;

}
} // namespace Flowers


