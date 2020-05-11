

#include <Flowers/Gameboard.hpp>
#include <Flowers/FlowerGenerator.hpp>
#include <stdexcept>


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
   , featured_flowers({})
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


std::vector<Flowers::Flower> &Gameboard::get_featured_flowers_ref()
{
   return featured_flowers;
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

Flowers::Flower* Gameboard::flower_at(int x, int y)
{
if (x < 0 || y < 0) return nullptr;
if (x >= num_columns || y >= num_rows) return nullptr;
return &flowers[x + y*num_columns];

}

Flowers::Flower Gameboard::flower_at_cursor()
{
Flowers::Flower *flower = flower_at(cursor_x, cursor_y);
if (!flower) throw std::runtime_error("Flowers/Gameboard.flower_at_cursor unexpectedly returned nullptr");
return *flower;

}

void Gameboard::move_cursor_up()
{
cursor_y -= 1;
while (cursor_y < 0) cursor_y += num_rows;
return;

}

void Gameboard::move_cursor_down()
{
cursor_y += 1;
if (cursor_y >= num_rows) cursor_y = cursor_y % num_rows;
return;

}

void Gameboard::move_cursor_left()
{
cursor_x -= 1;
while (cursor_x < 0) cursor_x += num_columns;
return;

}

void Gameboard::move_cursor_right()
{
cursor_x += 1;
if (cursor_x >= num_columns) cursor_x = cursor_x % num_columns;
return;

}

void Gameboard::pick_flower()
{
featured_flowers.push_back(flower_at_cursor());

}
} // namespace Flowers


