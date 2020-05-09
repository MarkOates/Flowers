#pragma once




namespace Flowers
{
   namespace Gameplay
   {
      class Board
      {
      private:
         int cursor_x;
         int cursor_y;

      public:
         Board();
         ~Board();


      void move_cursor_up();
      void move_cursor_down();
      void move_cursor_left();
      void move_cursor_right();
      };
   }
}



