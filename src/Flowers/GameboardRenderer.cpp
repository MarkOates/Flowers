

#include <Flowers/GameboardRenderer.hpp>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <Flowers/FlowerRenderer.hpp>
#include <allegro_flare/placement2d.h>


namespace Flowers
{


GameboardRenderer::GameboardRenderer(Flowers::Gameboard* gameboard)
   : gameboard_width((1920 * 0.6))
   , gameboard_height((1080 * 0.5))
   , gameboard(gameboard)
{
}


GameboardRenderer::~GameboardRenderer()
{
}


void GameboardRenderer::render()
{
if (!gameboard)
{
   throw std::runtime_error("[Flowers::GameboardRenderer.render error]: gameboard cannot be a nullptr");
}

al_draw_filled_rectangle(0, 0, gameboard_width, gameboard_height, al_color_name("saddlebrown"));
al_draw_rectangle(0, 0, gameboard_width, gameboard_height, al_color_name("saddlebrown"), 3.0);

for (auto &flower : gameboard->get_flowers_ref())
{
   allegro_flare::placement2d flower_placement(flower.get_x(), flower.get_y(), 0, 0);
   flower_placement.start_transform();
   Flowers::FlowerRenderer renderer(&flower);
   renderer.render();
   flower_placement.restore_transform();
}

}

std::string GameboardRenderer::run()
{
return "Hello World!";
}
} // namespace Flowers


