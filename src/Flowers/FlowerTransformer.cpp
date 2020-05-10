

#include <Flowers/FlowerTransformer.hpp>
#include <allegro5/allegro.h>
#include <AllegroFlare/Color.hpp>


namespace Flowers
{


FlowerTransformer::FlowerTransformer(Flowers::Flower* source_flower)
   : source_flower(source_flower)
{
}


FlowerTransformer::~FlowerTransformer()
{
}


int FlowerTransformer::random_int_incl(int min, int max)
{
return rand()%(max-min+1) + min;

}

float FlowerTransformer::random_float_incl(int min, int max)
{
return ((float) rand()/RAND_MAX)*(max-min) + min;
//return 0.0f;

}

ALLEGRO_COLOR FlowerTransformer::random_color()
{
return al_map_rgb(random_int_incl(0, 255), random_int_incl(0, 255), random_int_incl(0, 255));

}

Flowers::Flower FlowerTransformer::mutation()
{
Flowers::Flower flower = *source_flower;

flower.set_peduncle_height(flower.get_peduncle_height() * random_float_incl(0.7f, 1.24f));
ALLEGRO_COLOR original_color = flower.get_petal_color();
ALLEGRO_COLOR variance_color = random_color();
float mix_ratio = 0.3;
ALLEGRO_COLOR mix = AllegroFlare::color::mix(original_color, variance_color, mix_ratio);
flower.set_petal_color(mix);

return flower;

}

std::vector<Flowers::Flower> FlowerTransformer::mutations()
{
int number_of_mutations = random_int_incl(3, 7);
std::vector<Flowers::Flower> results = {};

for (int i=0; i<number_of_mutations; i++)
{
   results.push_back(mutation());
}
return results;

}
} // namespace Flowers


