

#include <Flowers/FlowerTransformer.hpp>
#include <AllegroFlare/Color.hpp>
#include <sstream>
#include <sstream>


namespace Flowers
{


FlowerTransformer::FlowerTransformer(Flowers::Flower* source_flower, AllegroFlare::Random* random)
   : source_flower(source_flower)
   , random(random)
{
}


FlowerTransformer::~FlowerTransformer()
{
}


Flowers::Flower FlowerTransformer::mutation()
{
if (!(source_flower))
{
   std::stringstream error_message;
   error_message << "FlowerTransformer" << "::" << "mutation" << ": error: " << "guard \"source_flower\" not met";
   throw std::runtime_error(error_message.str());
}
if (!(random))
{
   std::stringstream error_message;
   error_message << "FlowerTransformer" << "::" << "mutation" << ": error: " << "guard \"random\" not met";
   throw std::runtime_error(error_message.str());
}
Flowers::Flower flower = *source_flower;

// height
flower.set_peduncle_height(flower.get_peduncle_height() * random->get_random_float(0.7f, 1.24f));

// pedal color
ALLEGRO_COLOR original_color = flower.get_petal_color();
ALLEGRO_COLOR variance_color = random->get_random_color();
float mix_ratio = 0.2;
ALLEGRO_COLOR mix = AllegroFlare::color::mix(original_color, variance_color, mix_ratio);
flower.set_petal_color(mix);

return flower;

}

std::vector<Flowers::Flower> FlowerTransformer::mutations()
{
if (!(source_flower))
{
   std::stringstream error_message;
   error_message << "FlowerTransformer" << "::" << "mutations" << ": error: " << "guard \"source_flower\" not met";
   throw std::runtime_error(error_message.str());
}
if (!(random))
{
   std::stringstream error_message;
   error_message << "FlowerTransformer" << "::" << "mutations" << ": error: " << "guard \"random\" not met";
   throw std::runtime_error(error_message.str());
}
int number_of_mutations = random->get_random_int(3, 7);
std::vector<Flowers::Flower> results = {};

for (int i=0; i<number_of_mutations; i++)
{
   results.push_back(mutation());
}
return results;

}
} // namespace Flowers


