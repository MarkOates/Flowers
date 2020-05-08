

#include <Flowers/FlowerRenderer.hpp>



namespace Flowers
{


FlowerRenderer::FlowerRenderer(Flowers::Flower* flower)
   : flower(flower)
{
}


FlowerRenderer::~FlowerRenderer()
{
}


void FlowerRenderer::render()
{
if (!flower) throw std::runtime_error("[Flower::FlowerRenderer.render() error]: You must pass a valid flower");
return;

}
} // namespace Flowers


