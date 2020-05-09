

#include <FlowersGame/Game.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <Flowers/FlowerRenderer.hpp>
#include <allegro5/allegro.h>


namespace FlowersGame
{


Game::Game(AllegroFlare::Framework* framework, AllegroFlare::FontBin* font_bin)
   : AllegroFlare::Screen({})
   , framework(framework)
   , font_bin(font_bin)
   , showing_title(true)
   , flower_of_interest()
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
Flowers::FlowerRenderer(&flower_of_interest).render();
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


