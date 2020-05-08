

#include <Flowers/FlowerRenderer.hpp>
#include <stdexcept>
#include <allegro5/allegro_primitives.h>
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

float peduncle_height = flower->get_peduncle_height();
float peduncle_thickness = 8.0f;
ALLEGRO_COLOR peduncle_color = al_color_name("green");

ALLEGRO_COLOR outline_color = al_color_name("purple");
float outline_thickness = 4.0f;
ALLEGRO_COLOR color = flower->get_color();
float stigma_radius = 10.0f;

al_draw_line(0, 0, 0, -peduncle_height, peduncle_color, peduncle_thickness);

float receptacle_y = flower->calculate_receptacle_y() * -1;

al_draw_filled_circle(0, receptacle_y, stigma_radius, color);
al_draw_circle(0, receptacle_y, stigma_radius, outline_color, outline_thickness);

return;

}
} // namespace Flowers


