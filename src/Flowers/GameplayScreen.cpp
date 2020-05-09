

#include <Flowers/GameplayScreen.hpp>
#include <Flowers/LargeTextRenderer.hpp>
#include <Flowers/FlowerGenerator.hpp>
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
   , gameboard_width((1920 * 0.6))
   , gameboard_height((1080 * 0.5))
   , quote_generator({})
{
}


GameplayScreen::~GameplayScreen()
{
}


void GameplayScreen::spawn_quote()
{
if (!font_bin) throw std::runtime_error("Flowers/GameplayScreen::spawn_quote: error: font_bin is a nullptr");

//ALLEGRO_COLOR background_color = al_color_html("c6dee7");
ALLEGRO_FONT *quote_font = font_bin->operator[]("Voga-Medium.otf 32");
std::pair<std::string, std::string> quote = quote_generator.generate_quote();
Flowers::LargeTextRenderer large_text_renderer(quote_font, quote.first);
Flowers::LargeTextScroller large_text_scroller(large_text_renderer.create_bitmap());
large_text_scrollers.push_back(large_text_scroller);

}

void GameplayScreen::spawn_initial_flowers()
{
int num_columns = 6;
int num_rows = 4;

float cell_width = (float)gameboard_width / num_columns;
float cell_height = (float)gameboard_height / num_rows;

Flowers::FlowerGenerator flower_generator;

for (unsigned y=0; y<num_rows; y++)
{
   for (unsigned x=0; x<num_columns; x++)
   {
      Flowers::Flower flower = flower_generator.generate_random_flower();

      flower.set_x(cell_width * x + cell_width * 0.5);
      flower.set_y(cell_height * y + cell_height * 0.5);

      flowers.push_back(flower);
   }
}
return;

}

void GameplayScreen::initialize()
{
spawn_initial_flowers();
return;

}

void GameplayScreen::key_down_func(ALLEGRO_EVENT* ev)
{
switch(ev->keyboard.keycode)
{
case ALLEGRO_KEY_1:
   spawn_quote();
   break;
default:
   break;
}
return;

}

void GameplayScreen::primary_timer_func()
{
ALLEGRO_COLOR deep_green = al_color_html("004e2c");
ALLEGRO_COLOR light_blue = al_color_html("c6dee7");
ALLEGRO_COLOR background_color = deep_green;
al_clear_to_color(background_color);

// update

for (auto &large_text_scroller : large_text_scrollers)
{
   large_text_scroller.increment_by_step();
}
for (auto &flower : flowers)
{
   Flowers::FlowerUpdater updater(&flower);
   updater.update();
}


// draw

allegro_flare::placement2d place(screen_width/2, screen_height/2, gameboard_width, gameboard_height);
place.align = AllegroFlare::vec2d(0.5, 0.5);
place.start_transform();

al_draw_filled_rectangle(0, 0, gameboard_width, gameboard_height, al_color_name("saddlebrown"));
al_draw_rectangle(0, 0, gameboard_width, gameboard_height, al_color_name("saddlebrown"), 3.0);

for (auto &flower : flowers)
{
   allegro_flare::placement2d flower_placement(flower.get_x(), flower.get_y(), 0, 0);
   flower_placement.start_transform();
   Flowers::FlowerRenderer renderer(&flower);
   renderer.render();
   flower_placement.restore_transform();
}
for (auto &large_text_scroller : large_text_scrollers)
{
   large_text_scroller.draw();
}

place.restore_transform();


// cleanup

for (int i=0; i<large_text_scrollers.size(); i++)
{
   Flowers::LargeTextScroller &large_text_scroller = large_text_scrollers[i];
   if (large_text_scroller.get_finished())
   {
      al_destroy_bitmap(large_text_scroller.get_bitmap());
      large_text_scrollers.erase(large_text_scrollers.begin() + i);
      i--;
   }
}
return;

}
} // namespace Flowers


