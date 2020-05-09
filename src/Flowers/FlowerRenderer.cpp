

#include <Flowers/FlowerRenderer.hpp>
#include <cmath>
#include <cmath>
#include <stdexcept>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>


namespace Flowers
{


FlowerRenderer::FlowerRenderer(Flowers::Flower* flower)
   : flower(flower)
   , outline_thickness(4.0f)
   , outline_color(al_color_name("purple"))
   , TAU(6.283f)
{
}


FlowerRenderer::~FlowerRenderer()
{
}


void FlowerRenderer::render_petals()
{
float petal_radius = 10.0f;
float anchor_x = 0;
float anchor_y = flower->calculate_receptacle_y();
float petal_distance_from_center = 20.0f;
ALLEGRO_COLOR petal_color = flower->get_petal_color();
for (int i=0; i<flower->get_num_petals(); i++)
{
   float rotation = (float)i / flower->get_num_petals();
   float x = anchor_x + std::sin(rotation * TAU) * petal_distance_from_center;
   float y = anchor_y + std::cos(rotation * TAU) * petal_distance_from_center;
   al_draw_filled_circle(x, -y, petal_radius, petal_color);
}
return;

}

void FlowerRenderer::render_pistil()
{
float receptacle_y = flower->calculate_receptacle_y();
float y = receptacle_y;
float stigma_radius = 10.0f;
ALLEGRO_COLOR pistil_color = flower->get_pistil_color();

al_draw_filled_circle(0, -y, stigma_radius, pistil_color);
//al_draw_circle(0, -y, stigma_radius, outline_color, outline_thickness);
return;

}

void FlowerRenderer::render_peduncle()
{
float peduncle_height = flower->get_peduncle_height();
float peduncle_thickness = flower->get_peduncle_thickness();
ALLEGRO_COLOR peduncle_color = al_color_name("green");

al_draw_line(0, 0, 0, -peduncle_height, peduncle_color, peduncle_thickness);
return;

}

void FlowerRenderer::render_null_flower()
{
ALLEGRO_COLOR null_flower_placeholder_color{64, 64, 64, 64};
al_draw_filled_circle(0, 0, 10.0f, null_flower_placeholder_color);

}

void FlowerRenderer::render()
{
if (!flower) throw std::runtime_error("[Flower::FlowerRenderer.render() error]: You must pass a valid flower");
//if (!al_is_primitives_addon_initialized())
//   throw std::runtime_error("[Flower::FlowerRenderer.render() error]: You must al_init_primitives_addon()");

if (flower->get_null_object())
{
   render_null_flower();
}
else
{
   render_peduncle();
   render_petals();
   render_pistil();
}

return;

}
} // namespace Flowers


