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


      std::vector<Flowers::Flower> &get_flowers_ref();
   void spawn_initial_flowers();
   void move_cursor_up();
   void move_cursor_down();
   void move_cursor_left();
   void move_cursor_right();
   };
}



