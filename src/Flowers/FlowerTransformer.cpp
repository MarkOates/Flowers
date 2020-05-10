

#include <Flowers/FlowerTransformer.hpp>



namespace Flowers
{


FlowerTransformer::FlowerTransformer(Flowers::Flower* source_flower)
   : source_flower(source_flower)
{
}


FlowerTransformer::~FlowerTransformer()
{
}


std::vector<Flowers::Flower> FlowerTransformer::mutations()
{
return {};

}
} // namespace Flowers


