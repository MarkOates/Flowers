

#include <AllegroFlare/FrameworkScreenRegistrar.hpp>



namespace AllegroFlare
{


FrameworkScreenRegistrar::FrameworkScreenRegistrar(AllegroFlare::Screens* screens, AllegroFlare::Screen* screen)
   : screens(screens)
   , screen(screen)
{
}


FrameworkScreenRegistrar::~FrameworkScreenRegistrar()
{
}


bool FrameworkScreenRegistrar::append()
{
if (!screens) throw std::runtime_error("[AllegroFlare::FrameworkScreenRegistrar.append]: nullptr screens");
if (!screen) throw std::runtime_error("[AllegroFlare::FrameworkScreenRegistrar.append]: nullptr screen");

screens->add(screen);
return true;

}

bool FrameworkScreenRegistrar::remove()
{
if (!screens) throw std::runtime_error("[AllegroFlare::FrameworkScreenRegistrar.remove]: nullptr screens");
if (!screen) throw std::runtime_error("[AllegroFlare::FrameworkScreenRegistrar.remove]: nullptr screen");

screens->remove(screen);
return true;

}
} // namespace AllegroFlare


