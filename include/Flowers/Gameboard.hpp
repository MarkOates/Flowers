#pragma once


#include <Flowers/Flower.hpp>
#include <vector>


namespace Flowers
{
   class Gameboard
   {
   private:
      int cursor_x;
      int cursor_y;
      int width;
      int height;
      std::vector<Flowers::Flower> flowers;
      int num_columns;
      int num_rows;
      std::vector<Flowers::Flower> featured_flowers;

   public:
      Gameboard();
      ~Gameboard();


      int get_cursor_x();
      int get_cursor_y();
      int get_width();
      int get_height();
      std::vector<Flowers::Flower> &get_flowers_ref();
      std::vector<Flowers::Flower> &get_featured_flowers_ref();
   float calc_cell_width();
   float calc_cell_height();
   void spawn_initial_flowers();
   Flowers::Flower* flower_at(int x=0, int y=0);
   Flowers::Flower flower_at_cursor();
   void move_cursor_up();
   void move_cursor_down();
   void move_cursor_left();
   void move_cursor_right();
   void pick_flower();
   };
}



