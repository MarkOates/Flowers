

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
if (finished) return;
offset += scroll_speed;
if (offset > al_get_bitmap_width(bitmap)) finished = true;
return;

}

void LargeTextScroller::draw()
{
al_draw_bitmap(bitmap, -offset, 0, 0);
return;

}
} // namespace Flowers


