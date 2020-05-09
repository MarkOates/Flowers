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

   public:
      Gameboard();
      ~Gameboard();


      int get_cursor_x();
      int get_cursor_y();
      int get_width();
      int get_height();
      std::vector<Flowers::Flower> &get_flowers_ref();
   float calc_cell_width();
   float calc_cell_height();
   void spawn_initial_flowers();
   void move_cursor_up();
   void move_cursor_down();
   void move_cursor_left();
   void move_cursor_right();
   };
}



