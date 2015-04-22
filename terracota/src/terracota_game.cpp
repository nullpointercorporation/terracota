#include "terracota_game.h"
#include "terracota_front_end.h"

Terracota::Terracota()
    : Game("a")
{
}

Level *
Terracota::load_level(const string& id)
{
    if (id == "a")
    {
        return new FrontEnd("b", "res/images/logo-terracota.jpg");
    }
    else if (id == "b")
    {
        return new FrontEnd("c", "res/images/logo-sdl.png");
    }
    else if (id == "c")
    {
        return new FrontEnd("", "res/images/spiral.png");
    }

    return nullptr;
}

