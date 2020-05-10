

#include <FlowersGame/Game.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <cmath>
#include <Flowers/FlowerTransformer.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <Flowers/FlowerRenderer.hpp>
#include <allegro_flare/placement2d.h>
#include <allegro5/allegro.h>


namespace FlowersGame
{


Game::Game(AllegroFlare::Framework* framework, AllegroFlare::FontBin* font_bin, AllegroFlare::Motion* motion)
   : AllegroFlare::Screen({})
   , framework(framework)
   , font_bin(font_bin)
   , motion(motion)
   , showing_title(true)
   , flower_of_interest()
   , mutations({})
   , state("undefined")
{
}


Game::~Game()
{
}


ALLEGRO_DISPLAY* Game::infer_display()
{
return al_get_current_display();
}

void Game::draw_press_enter_text()
{
int display_width = al_get_display_width(infer_display());
int display_height = al_get_display_height(infer_display());
ALLEGRO_FONT *font = font_bin->operator[]("Montserrat-Regular.ttf 28");
ALLEGRO_COLOR color = al_color_html("9bb6d3");
float line_height = al_get_font_line_height(font);
std::string title = "Copyright 2020 - Mark Oates";
al_draw_text(font, color, display_width/2, display_height/2 - line_height/2 + 200, ALLEGRO_ALIGN_CENTER, title.c_str());
return;

}

void Game::start_game()
{
showing_title = false;
      create_mutations();
      reveal_mutations();
return;

}

void Game::reveal_mutations()
{
float TAU = 3.14159 * 2;
//int num_mutations = mutations.size();
for (int i=0; i<mutations.size(); i++)
{
   auto &mutation = mutations[i];
   float delta = (float) i / mutations.size();
   float radius = 300;
   float dest_x = std::sin(delta * TAU) * radius;
   float dest_y = std::cos(delta * TAU) * radius;
   motion->cmove_to(&mutation.get_x_ref(), dest_x, 2.0, AllegroFlare::interpolator::double_fast_in);
   motion->cmove_to(&mutation.get_y_ref(), dest_y, 2.0, AllegroFlare::interpolator::tripple_fast_in);
}
return;

}

void Game::create_mutations()
{
Flowers::FlowerTransformer mutator(&flower_of_interest);
mutations = mutator.mutations();
return;

}

void Game::draw_title()
{
int display_width = al_get_display_width(infer_display());
int display_height = al_get_display_height(infer_display());
ALLEGRO_FONT *font = font_bin->operator[]("BodoniFLF-Roman.ttf 190");
//7c3658
//344b6d
ALLEGRO_COLOR color = al_color_html("344b6d");
//ALLEGRO_COLOR color = al_color_html("7c3658");
float line_height = al_get_font_line_height(font);
std::string title = "f  l  o  w  e  r  s";
al_draw_text(font, color, display_width/2, display_height/2 - line_height/2, ALLEGRO_ALIGN_CENTER, title.c_str());

draw_press_enter_text();

}

void Game::draw_gameplay()
{
// draw flower of focus

allegro_flare::placement2d camera_transform(0, 0, 1920, 1080);
camera_transform.align = AllegroFlare::vec2d(0.5, 0.5);
camera_transform.start_reverse_transform();

Flowers::FlowerRenderer(&flower_of_interest).render();

for (auto &mutation : mutations)
{
   allegro_flare::placement2d flower_transform(mutation.get_x(), mutation.get_y(), 0, 0);
   flower_transform.start_transform();
   Flowers::FlowerRenderer(&mutation).render();
   flower_transform.restore_transform();
}

camera_transform.restore_transform();

return;

}

void Game::key_down_func(ALLEGRO_EVENT* ev)
{
switch(ev->keyboard.keycode)
{
case ALLEGRO_KEY_ESCAPE:
   framework->shutdown_program = true;
   break;
case ALLEGRO_KEY_ENTER:
   start_game();
   break;
case ALLEGRO_KEY_M:
   if (mutations.empty())
   {
      create_mutations();
      reveal_mutations();
   }
   break;
}
return;

}

void Game::primary_timer_func()
{
ALLEGRO_COLOR background_color = al_color_html("c6dee7");
al_clear_to_color(background_color);

if (showing_title) draw_title();
else draw_gameplay();

return;

}
} // namespace FlowersGame


