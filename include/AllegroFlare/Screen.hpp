#pragma once


#include <string>
#include <vector>
#include <allegro5/allegro.h>
#include <AllegroFlare/Display.hpp>
#include <AllegroFlare/Framework.hpp>
#include <AllegroFlare/Screens.hpp>




namespace AllegroFlare
{
   class Screen
   {
   private:
      friend class Framework;
      friend class Display;

      bool initialized;

   public:
      Framework *framework;
      Screens *screens;
      ALLEGRO_BITMAP *backbuffer_sub_bitmap;
      Display *display;

      Screen(Framework *framework=nullptr, Screens *screens=nullptr, Display *display=nullptr);
      virtual ~Screen();

      // expecting target to be bitmap of ALLEGRO_DISPLAY, e.g. al_get_backbuffer(display->al_display);
      void create_and_use_backbuffer_sub_bitmap_of(ALLEGRO_BITMAP *new_target);
      void set_on_display(Display *display);
      void prepare_drawing_state(bool prepare_3d=false);

      void initialize();
      void destruct();

      virtual void on_event(ALLEGRO_EVENT *ev);

      virtual void primary_timer_func();
      virtual void timer_func();
      virtual void display_switch_in_func();
      virtual void display_switch_out_func();
      virtual void mouse_axes_func();
      virtual void mouse_warp_func();
      virtual void mouse_down_func();
      virtual void mouse_up_func();
      virtual void key_down_func();
      virtual void key_up_func();
      virtual void key_char_func();
      virtual void joy_button_down_func();
      virtual void joy_button_up_func();
      virtual void joy_axis_func();
      virtual void joy_config_func();
      virtual void user_event_func();
      virtual void native_menu_click_func();
      virtual void receive_signal(int signal, void *data);
      virtual void receive_signal(std::string const signal, void *data);
   };
}


