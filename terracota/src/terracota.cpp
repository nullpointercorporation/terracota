#include "terracota.h"

#include <util/frontend.h>
#include "titlescreen.h"
#include "settings.h"
#include "stage.h"
#include "gameflow.h"

Terracota::Terracota()
    : Game ("a")
{
}

Level*
Terracota::load_level(const string& id)
{
	GameFlow::get_instance()->set_state(GameState::FRONT_END);
    if (id == "a")
       return new FrontEnd("a","b","res/images/logos/logo-terracota.jpg");
    if (id == "b")
        return new FrontEnd("b","c","res/images/logos/logo-sdl.png");
    if (id == "c")
        return new FrontEnd("c","title", "res/images/logos/faixa_etaria.jpg");
    if (id == "title")
        return new TitleScreen();
    if (id == "settings")
        return new Settings();
	if (id == "stage1")
		return new Stage("stage1","res/images/stages/first_map/1.jpg",500,200,800,600);

    
    return nullptr; 
}

bool
Terracota::onKeyboardEvent(const KeyboardEvent& event)
{
	GameState state  = GameFlow::get_instance()->state();
	
    if (event.state() == KeyboardEvent::PRESSED
        and event.key() == KeyboardEvent::ESCAPE 
		and (state == GameState::MENU or state == GameState::FRONT_END) )
    {
        m_done = true;
        return true;
    }

	return false;
}

