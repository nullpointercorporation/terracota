#include "terracota.h"

#include <util/frontend.h>

#include "titlescreen.h"
#include "options.h"
#include "stage.h"
#include "gameflow.h"
#include "gameover.h"
#include "map.h"


#include <iostream>
using namespace std;

Terracota::Terracota()
    : Game ("a")
{
}

Level*
Terracota::load_level(const string& id)
{
	GameFlow::get_instance()->set_state(GameState::FRONT_END);
    if (id == "a")
       return new FrontEnd("a","b","res/images/logos/logo.png", 3000, Color(137, 137, 137));
    if (id == "b")
        return new FrontEnd("b","c","res/images/logos/logo-sdl.png");
    if (id == "c")
        return new FrontEnd("c","title", "res/images/logos/faixa_etaria.png");
    if (id == "title")
	{
        return new TitleScreen();
	}
    if (id == "options")
        return new Options();

	if (id == "map1")
	{
    	list<string> objects ={"background", "water_fountain", "home",	"tree", "light", "sidewalk","door"};
		return new Map("map1","res/conf/map1.conf",objects);
	}


	if (id == "map2")
	{	
        list<string> objects ={
            "background", "water", "home",  "door",
            "lamber1", "lamber2", "grass1", "grass2",
            "grass3",  "grass4","tree",   "branch", "rock","home2"};
		return new Map("map2","res/conf/map2.conf",objects);
	}



	if (id == "gameover")
		return new GameOver(); 
    
    return nullptr; 
}

bool
Terracota::on_event(const KeyboardEvent& event)
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

