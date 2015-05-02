#include "terracota.h"

#include "frontend.h"
#include "titlescreen.h"
#include "stage.h"


Terracota::Terracota()
    : Game ("a")
{
}

Level*
Terracota::load_level(const string& id)
{
    if (id == "a")
       return new FrontEnd("b","res/images/logo-terracota.jpg");
    if (id == "b")
        return new FrontEnd("c","res/images/logo-sdl.png");
    if (id == "c")
        return new FrontEnd("title", "res/images/faixa_etaria.jpg");
    if (id == "title")
        return new TitleScreen();
    if (id == "stage1")
        return new Stage("stage1");
    return nullptr; 
}
