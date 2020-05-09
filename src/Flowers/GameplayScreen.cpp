

#include <Flowers/GameplayScreen.hpp>
#include <allegro_flare/placement2d.h>
#include <Flowers/FlowerRenderer.hpp>


namespace Flowers
{


GameplayScreen::GameplayScreen(AllegroFlare::FontBin* font_bin, int screen_width, int screen_height)
   : AllegroFlare::Screen({})
   , font_bin(font_bin)
   , flowers({})
   , screen_width(screen_width)
   , screen_height(screen_height)
   , gameboard_width(600)
   , gameboard_height(300)
{
}


GameplayScreen::~GameplayScreen()
{
}


void GameplayScreen::initialize()
{
Flowers::Flower flower;
flower.set_peduncle_height(40);
flowers.push_back(flower);
return;

}

void GameplayScreen::primary_timer_func()
{
allegro_flare::placement2d place(0, 0, gameboard_width, gameboard_height);
place.align = AllegroFlare::vec2d(0.5, 0.5);
place.start_transform();

for (auto &flower : flowers)
{
   Flowers::FlowerRenderer renderer(&flower);
   renderer.render();
}

place.restore_transform();
return;

}
} // namespace Flowers


