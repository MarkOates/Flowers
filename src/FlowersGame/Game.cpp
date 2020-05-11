

#include <FlowersGame/Game.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro.h>
#include <Flowers/Achievements/FourLeaf.hpp>
#include <Flowers/Achievements/Peduncle.hpp>
#include <Flowers/Achievements/Saturated.hpp>
#include <Flowers/Achievements/DarkPetals.hpp>
#include <cmath>
#include <Flowers/FlowerTransformer.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <Flowers/FlowerRenderer.hpp>
#include <allegro_flare/placement2d.h>
#include <allegro5/allegro.h>
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
   , random(12345)
   , achievements({})
   , achieved({})
   , selection_time(0.0f)
{
}


Game::~Game()
{
}


void Game::set_flower_of_interest(Flowers::Flower flower_of_interest)
{
   this->flower_of_interest = flower_of_interest;
}


void Game::set_selection_time(float selection_time)
{
   this->selection_time = selection_time;
}


Flowers::Flower Game::get_flower_of_interest()
{
   return flower_of_interest;
}


std::vector<std::string> &Game::get_achieved_ref()
{
   return achieved;
}


void Game::dump_flower_of_interest_stats()
{
Flowers::Flower f = flower_of_interest;
std::cout << "sat: " << f.calc_petal_color_saturation() << std::endl;
std::cout << "val: " << f.calc_petal_color_value() << std::endl;

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

void Game::load_achievements()
{
achievements.add("Four Petal Flower", new Flowers::Achievements::FourLeaf(this));
achievements.add("Peduncle", new Flowers::Achievements::Peduncle(this));
achievements.add("Saturated Color", new Flowers::Achievements::Saturated(this));
achievements.add("Dark Petals", new Flowers::Achievements::DarkPetals(this));
return;

}

void Game::start_game()
{
load_achievements();
showing_title = false;
flower_of_interest = Flowers::Flower();
flower_of_interest.set_created_at(al_get_time());
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
   float speed = mutation.get_speed_sec();

   motion->cmove_to(&mutation.get_x_ref(), dest_x, speed, AllegroFlare::interpolator::double_fast_in);
   motion->cmove_to(&mutation.get_y_ref(), dest_y, speed, AllegroFlare::interpolator::tripple_fast_in);
}
return;

}

void Game::create_mutations()
{
clear_mutations();

Flowers::FlowerTransformer mutator(&flower_of_interest, &random);
mutations = mutator.mutations();

return;

}

void Game::move_camera_to(float dest_x, float dest_y)
{
motion->cmove_to(&camera_transform.position.x, dest_x, 2.0, AllegroFlare::interpolator::double_fast_in);
motion->cmove_to(&camera_transform.position.y, dest_y, 2.0, AllegroFlare::interpolator::tripple_fast_in);
return;

}

void Game::check_achievements()
{
achievements.check_all();
return;

}

void Game::select_mutation(int index)
{
if (index < 0 || index >= mutations.size())
{
   throw std::runtime_error("could not select mutation, index out of bounds");
}

// safe the previous flower
flower_history.push_back(flower_of_interest);

// set the new flower (and create_time)
flower_of_interest = mutations[index];
flower_of_interest.set_created_at(al_get_time());
flower_of_interest.set_spawned_offspring(false);

dump_flower_of_interest_stats();

// move the camera
move_camera_to(flower_of_interest.get_x(), flower_of_interest.get_y());

clear_mutations();

check_achievements();

set_selection_time(al_get_time());

return;

}

void Game::draw_achievements()
{
ALLEGRO_FONT *font = font_bin->operator[]("Montserrat-Regular.ttf 22");
ALLEGRO_COLOR color = al_color_name("gray");
float line_height = al_get_font_line_height(font);
int display_width = al_get_display_width(infer_display());
int display_height = al_get_display_height(infer_display());
std::vector<std::string> elements = achieved;
//{ std::string("Four Leaf Clover"), std::string("Saturated"), std::string("Golden Rose") };
float distance = 200;
float start_x = display_width/2 - (distance * (elements.size() - 1)) / 2;
int counter = 0;
for (auto &ach : elements) //achieved)
{
   al_draw_text(font, color,
      start_x + distance * counter,
      display_height - 100,
      ALLEGRO_ALIGN_CENTER,
      ach.c_str()
   );
   counter++;
}

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

for (auto &flower : flower_history)
{
   allegro_flare::placement2d flower_transform(flower.get_x(), flower.get_y(), 0, 0);
   flower_transform.start_transform();
   Flowers::FlowerRenderer(&flower).render();
   flower_transform.restore_transform();
}

// draw flower of interest

allegro_flare::placement2d flower_transform(flower_of_interest.get_x(), flower_of_interest.get_y(), 0, 0);
flower_transform.start_transform();
Flowers::FlowerRenderer(&flower_of_interest, true).render();
flower_transform.restore_transform();

// draw mutations

int mutation_num = 0;
for (auto &flower : mutations)
{
   allegro_flare::placement2d flower_transform(flower.get_x(), flower.get_y(), 0, 0);
   flower_transform.start_transform();
   Flowers::FlowerRenderer(&flower).render();

   // draw keyboard input
   ALLEGRO_FONT *font = font_bin->operator[]("Montserrat-Regular.ttf 22");
   ALLEGRO_COLOR color = al_color_html("344b6d");
   std::stringstream selection_input;
   selection_input << (char)(mutation_num + 1 + 64);
   al_draw_text(font, color, 0, 20, ALLEGRO_ALIGN_CENTER, selection_input.str().c_str());

   flower_transform.restore_transform();

   mutation_num++;
}

camera_transform.restore_transform();

// draw achievements

draw_achievements();

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
   //if (mutations.empty())
   //{
      //create_mutations();
      //reveal_mutations();
   //}
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

check_achievements();

if (flower_of_interest.calc_offspring_duration() > flower_of_interest.get_speed_sec()
   && !flower_of_interest.get_spawned_offspring())
{
   flower_of_interest.set_spawned_offspring(true);
   create_mutations();
   reveal_mutations();
}

if (showing_title) draw_title();
else draw_gameplay();

return;

}
} // namespace FlowersGame


