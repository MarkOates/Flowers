

#include <Flowers/GameplayScreen.hpp>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <allegro_flare/placement2d.h>
#include <Flowers/FlowerUpdater.hpp>
#include <Flowers/FlowerRenderer.hpp>


namespace Flowers
{


GameplayScreen::GameplayScreen(AllegroFlare::FontBin* font_bin, int screen_width, int screen_height)
   : AllegroFlare::Screen({})
   , font_bin(font_bin)
   , flowers({})
   , large_text_scrollers({})
   , screen_width(screen_width)
   , screen_height(screen_height)
   , gameboard_width(600)
   , gameboard_height(300)
{
}


GameplayScreen::~GameplayScreen()
{
}


void GameplayScreen::spawn_initial_flowers()
{
int num_columns = 6;
int num_rows = 4;

float cell_width = (float)gameboard_width / num_columns;
float cell_height = (float)gameboard_height / num_rows;

for (unsigned y=0; y<num_rows; y++)
{
   for (unsigned x=0; x<num_columns; x++)
   {
      Flowers::Flower flower;
      flower.set_x(cell_width * x + cell_width * 0.5);
      flower.set_y(cell_height * y + cell_height * 0.5);
      flower.set_peduncle_height(40);
      flowers.push_back(flower);
   }
}
return;

}

void GameplayScreen::initialize()
{
spawn_initial_flowers();
return;

Flowers::Flower flower;
flower.set_x(gameboard_width/2);
flower.set_y(gameboard_height/2);
flower.set_peduncle_height(40);
flowers.push_back(flower);
return;

}

void GameplayScreen::primary_timer_func()
{
// update

for (auto &flower : flowers)
{
   Flowers::FlowerUpdater updater(&flower);
   updater.update();
}


// draw

allegro_flare::placement2d place(screen_width/2, screen_height/2, gameboard_width, gameboard_height);
place.align = AllegroFlare::vec2d(0.5, 0.5);
place.start_transform();

al_draw_rectangle(0, 0, gameboard_width, gameboard_height, al_color_name("saddlebrown"), 3.0);

for (auto &flower : flowers)
{
   allegro_flare::placement2d flower_placement(flower.get_x(), flower.get_y(), 0, 0);
   flower_placement.start_transform();
   Flowers::FlowerRenderer renderer(&flower);
   renderer.render();
   flower_placement.restore_transform();
}

place.restore_transform();
return;

}
} // namespace Flowers


