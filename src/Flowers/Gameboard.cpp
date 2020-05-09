

#include <Flowers/Gameboard.hpp>
#include <Flowers/FlowerGenerator.hpp>


namespace Flowers
{


Gameboard::Gameboard()
   : cursor_x(0)
   , cursor_y(0)
   , width((1920 * 0.6))
   , height((1080 * 0.5))
   , flowers({})
   , num_columns(6)
   , num_rows(4)
{
}


Gameboard::~Gameboard()
{
}


int Gameboard::get_cursor_x()
{
   return cursor_x;
}


int Gameboard::get_cursor_y()
{
   return cursor_y;
}


int Gameboard::get_width()
{
   return width;
}


int Gameboard::get_height()
{
   return height;
}


std::vector<Flowers::Flower> &Gameboard::get_flowers_ref()
{
   return flowers;
}


float Gameboard::calc_cell_width()
{
return (float)width / num_columns;
}

float Gameboard::calc_cell_height()
{
return (float)height / num_rows;
}

void Gameboard::spawn_initial_flowers()
{
float cell_width = calc_cell_width();
float cell_height = calc_cell_height();

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

void Gameboard::move_cursor_up()
{
return;

}

void Gameboard::move_cursor_down()
{
return;

}

void Gameboard::move_cursor_left()
{
return;

}

void Gameboard::move_cursor_right()
{
return;

}
} // namespace Flowers


