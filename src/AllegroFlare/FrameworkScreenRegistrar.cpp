

#include <AllegroFlare/FrameworkScreenRegistrar.hpp>



namespace AllegroFlare
{


FrameworkScreenRegistrar::FrameworkScreenRegistrar(AllegroFlare::Framework* framework, AllegroFlare::Screens* screens, AllegroFlare::Screen* screen)
   : framework(framework)
   , screens(screens)
   , screen(screen)
{
}


FrameworkScreenRegistrar::~FrameworkScreenRegistrar()
{
}


bool FrameworkScreenRegistrar::append()
{
return true;

}

bool FrameworkScreenRegistrar::remove()
{
return true;

}
} // namespace AllegroFlare


