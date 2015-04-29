#include "terracota.h"
#include "front_end.h"
#include "menu.h"

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
        return new FrontEnd("d", "res/images/faixa_etaria.jpg");
    }
    else if (id == "d")
	{
		return new Menu("","res/images/background.png");
	}

    return nullptr;
}

