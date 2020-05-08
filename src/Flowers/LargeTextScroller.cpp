

#include <Flowers/LargeTextScroller.hpp>



namespace Flowers
{


LargeTextScroller::LargeTextScroller(ALLEGRO_BITMAP* bitmap)
   : bitmap(bitmap)
   , offset(0.0f)
   , scroll_speed(1.0f)
   , finished(false)
{
}


LargeTextScroller::~LargeTextScroller()
{
}


bool LargeTextScroller::get_finished()
{
   return finished;
}


void LargeTextScroller::increment_by_step()
{
offset += scroll_speed;
return;

}

std::string LargeTextScroller::run()
{
return "Hello World!";
}

void LargeTextScroller::draw()
{
return;

}
} // namespace Flowers


