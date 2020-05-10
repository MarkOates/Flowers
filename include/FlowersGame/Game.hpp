#pragma once


#include <AllegroFlare/FontBin.hpp>
#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Motion.hpp>
#include <AllegroFlare/Screen.hpp>
#include <Flowers/Flower.hpp>
#include <allegro5/allegro.h>
#include <allegro_flare/placement2d.h>
#include <string>
#include <vector>


namespace FlowersGame
{
   class Game : public AllegroFlare::Screen
   {
   private:
      AllegroFlare::Framework* framework;
      AllegroFlare::FontBin* font_bin;
      AllegroFlare::Motion* motion;
      bool showing_title;
      Flowers::Flower flower_of_interest;
      std::vector<Flowers::Flower> mutations;
      std::vector<Flowers::Flower> flower_history;
      std::string state;
      allegro_flare::placement2d camera_transform;

   public:
      Game(AllegroFlare::Framework* framework=nullptr, AllegroFlare::FontBin* font_bin=nullptr, AllegroFlare::Motion* motion=nullptr);
      ~Game();


   ALLEGRO_DISPLAY* infer_display();
   void draw_press_enter_text();
   void start_game();
   void clear_mutations();
   void reveal_mutations();
   void create_mutations();
   void move_camera_to(float dest_x=0.0f, float dest_y=0.0f);
   void select_mutation(int index=0);
   void draw_title();
   void draw_gameplay();
   void key_char_func(ALLEGRO_EVENT* ev=nullptr) override;
   void key_down_func(ALLEGRO_EVENT* ev=nullptr) override;
   void primary_timer_func() override;
   };
}



