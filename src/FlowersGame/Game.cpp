

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
   , flower_history({})
   , state("undefined")
   , camera_transform(0, 0, 1920, 1080)
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
return;

}

void Game::clear_mutations()
{
for (int i=0; i<mutations.size(); i++)
{
   auto &mutation = mutations[i];
   motion->clear_animations_on(&mutation.get_x_ref());
   motion->clear_animations_on(&mutation.get_y_ref());
}
mutations.clear();

}

void Game::reveal_mutations()
{
float TAU = 3.14159 * 2;
//int num_mutations = mutations.size();
float source_flower_x = flower_of_interest.get_x();
float source_flower_y = flower_of_interest.get_y();

for (int i=0; i<mutations.size(); i++)
{
   auto &mutation = mutations[i];
   float delta = (float) i / mutations.size();
   float radius = 300;
   float dest_x = std::sin(delta * TAU) * radius + source_flower_x;
   float dest_y = std::cos(delta * TAU) * radius + source_flower_y;

   motion->cmove_to(&mutation.get_x_ref(), dest_x, 2.0, AllegroFlare::interpolator::double_fast_in);
   motion->cmove_to(&mutation.get_y_ref(), dest_y, 2.0, AllegroFlare::interpolator::tripple_fast_in);
}
return;

}

void Game::create_mutations()
{
clear_mutations();

Flowers::FlowerTransformer mutator(&flower_of_interest);
mutations = mutator.mutations();

return;

}

void Game::move_camera_to(float dest_x, float dest_y)
{
motion->cmove_to(&camera_transform.position.x, dest_x, 2.0, AllegroFlare::interpolator::double_fast_in);
motion->cmove_to(&camera_transform.position.y, dest_y, 2.0, AllegroFlare::interpolator::tripple_fast_in);
return;

}

void Game::select_mutation(int index)
{
if (index < 0 || index >= mutations.size())
{
   throw std::runtime_error("could not select mutation, index out of bounds");
}

flower_history.push_back(flower_of_interest);
flower_of_interest = mutations[index];
move_camera_to(flower_of_interest.get_x(), flower_of_interest.get_y());

clear_mutations();

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

//allegro_flare::placement2d camera_transform(0, 0, 1920, 1080);
camera_transform.align = AllegroFlare::vec2d(0.5, 0.5);
camera_transform.start_reverse_transform();

// draw flower history

for (auto &flower : mutations)
{
   allegro_flare::placement2d flower_transform(flower.get_x(), flower.get_y(), 0, 0);
   flower_transform.start_transform();
   Flowers::FlowerRenderer(&flower).render();
   flower_transform.restore_transform();
}

// draw flower of interest

allegro_flare::placement2d flower_transform(flower_of_interest.get_x(), flower_of_interest.get_y(), 0, 0);
flower_transform.start_transform();
Flowers::FlowerRenderer(&flower_of_interest).render();
flower_transform.restore_transform();

// draw mutations

int mutation_num = 0;
for (auto &flower : mutations)
{
   allegro_flare::placement2d flower_transform(flower.get_x(), flower.get_y(), 0, 0);
   flower_transform.start_transform();
   Flowers::FlowerRenderer(&flower).render();
   flower_transform.restore_transform();
   mutation_num++;
}

camera_transform.restore_transform();

return;

}

void Game::key_char_func(ALLEGRO_EVENT* ev)
{
char char_pressed = ev->keyboard.unichar;
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
case ALLEGRO_KEY_A:
   if (mutations.size() >= 1) select_mutation(0);
   break;
case ALLEGRO_KEY_B:
   if (mutations.size() >= 2) select_mutation(1);
   break;
case ALLEGRO_KEY_C:
   if (mutations.size() >= 3) select_mutation(2);
   break;
case ALLEGRO_KEY_D:
   if (mutations.size() >= 4) select_mutation(3);
   break;
case ALLEGRO_KEY_E:
   if (mutations.size() >= 5) select_mutation(4);
   break;
case ALLEGRO_KEY_F:
   if (mutations.size() >= 6) select_mutation(5);
   break;
case ALLEGRO_KEY_G:
   if (mutations.size() >= 7) select_mutation(6);
   break;
case ALLEGRO_KEY_H:
   if (mutations.size() >= 8) select_mutation(7);
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


