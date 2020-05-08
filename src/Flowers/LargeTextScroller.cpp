

#include <Flowers/LargeTextScroller.hpp>



namespace Flowers
{


LargeTextScroller::LargeTextScroller(ALLEGRO_BITMAP* bitmap, float scale)
   : bitmap(bitmap)
   , scale(scale)
   , scroll_speed(1.0f)
   , offset(0.0f)
   , finished(false)
{
}


LargeTextScroller::~LargeTextScroller()
{
}


void LargeTextScroller::set_scroll_speed(float scroll_speed)
{
   this->scroll_speed = scroll_speed;
}


bool LargeTextScroller::get_finished()
{
   return finished;
}


void LargeTextScroller::increment_by_step()
{
if (finished) return;
offset += (scroll_speed * scale);
if (offset > (al_get_bitmap_width(bitmap) * scale)) finished = true;
return;

}

void LargeTextScroller::draw()
{
float width = al_get_bitmap_width(bitmap);
float height = al_get_bitmap_height(bitmap);
float half_height = al_get_bitmap_height(bitmap)/2;
al_draw_scaled_bitmap(bitmap,
  0, 0, width, height,
  -offset, -half_height*scale, width*scale, height*scale,
  0);
return;

}
} // namespace Flowers


