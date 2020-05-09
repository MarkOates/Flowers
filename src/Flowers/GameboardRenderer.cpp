

#include <Flowers/GameboardRenderer.hpp>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <Flowers/FlowerRenderer.hpp>
#include <allegro_flare/placement2d.h>


namespace Flowers
{


GameboardRenderer::GameboardRenderer(Flowers::Gameboard* gameboard)
   : gameboard(gameboard)
{
}


GameboardRenderer::~GameboardRenderer()
{
}


void GameboardRenderer::draw_featured_flower()
{
//allegro_flare::placement2d featured_flower_placement(flower.get_x(), flower.get_y(), 0, 0);
//flower_placement.start_transform();
Flowers::Flower featured_flower = gameboard->get_featured_flower_ref();
//featured_flower.set_x(50);
//featured_flower.set_y(200);
Flowers::FlowerRenderer renderer(&featured_flower);
renderer.render();

}

void GameboardRenderer::draw_cursor()
{
int cursor_width = gameboard->calc_cell_width();
int cursor_height = gameboard->calc_cell_height();

int cursor_screen_x1 = gameboard->get_cursor_x() * cursor_width;
int cursor_screen_y1 = gameboard->get_cursor_y() * cursor_height;
int cursor_screen_x2 = cursor_screen_x1 + cursor_width;
int cursor_screen_y2 = cursor_screen_y1 + cursor_height;
ALLEGRO_COLOR cursor_color = al_color_name("yellow");
al_draw_rectangle(cursor_screen_x1, cursor_screen_y1, cursor_screen_x2, cursor_screen_y2, cursor_color, 9.0f);
return;

}

void GameboardRenderer::render()
{
if (!gameboard)
{
   throw std::runtime_error("[Flowers::GameboardRenderer.render error]: gameboard cannot be a nullptr");
}

// draw the dirt

float gameboard_width = gameboard->get_width();
float gameboard_height = gameboard->get_height();
al_draw_filled_rectangle(0, 0, gameboard_width, gameboard_height, al_color_name("saddlebrown"));
al_draw_rectangle(0, 0, gameboard_width, gameboard_height, al_color_name("saddlebrown"), 3.0);

// draw the cursor

draw_cursor();

// draw the flowers

for (auto &flower : gameboard->get_flowers_ref())
{
   allegro_flare::placement2d flower_placement(flower.get_x(), flower.get_y(), 0, 0);
   flower_placement.start_transform();
   Flowers::FlowerRenderer renderer(&flower);
   renderer.render();
   flower_placement.restore_transform();
}

// draw the cursor (overlay)

draw_featured_flower();

}

std::string GameboardRenderer::run()
{
return "Hello World!";
}
} // namespace Flowers


