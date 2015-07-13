#include "terracota.h"

#include <util/frontend.h>

#include "titlescreen.h"
#include "options.h"
#include "stage.h"
#include "gameflow.h"
#include "gameover.h"
#include "map.h"
#include "gamecontrol.h"
#include <core/environment.h>
#include "inti.h"
#include "killa.h"
#include "life.h"


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
        return new FrontEnd("c","d", "res/images/logos/faixa_etaria.png");
    if (id == "d")
        return new FrontEnd("d","e", "res/images/cutscenes/tutorial_01.png",15000);
    if (id == "e")
        return new FrontEnd("e","title","res/images/cutscenes/tutorial_02.png",15000 );

    if (id == "title")
	{
        return new TitleScreen();
	}

    if (id == "c1a")
        return new FrontEnd("c1a","c1b","res/images/cutscenes/c1a.png",15000);
    if (id == "c1b")
        return new FrontEnd("c1b","c1c","res/images/cutscenes/c1b.png",15000);
    if (id == "c1c")
        return new FrontEnd("c1c","c1d","res/images/cutscenes/c1c.png",15000);
    if (id == "c1d")
        return new FrontEnd("c1d","c1e","res/images/cutscenes/c1d.png",15000);
    if (id == "c1e")
        return new FrontEnd("c1e","c1f","res/images/cutscenes/c1e.png",15000);
    if (id == "c1f")
        return new FrontEnd("c1f","c1g","res/images/cutscenes/c1f.png",15000);
    if (id == "c1g")
        return new FrontEnd("c1g","c1h","res/images/cutscenes/c1g.png",15000);
    if (id == "c1h")
        return new FrontEnd("c1h","c1i","res/images/cutscenes/c1h.png",15000);
    if (id == "c1i")
        return new FrontEnd("c1i","c1j","res/images/cutscenes/c1i.png",15000);
    if (id == "c1j")
        return new FrontEnd("c1j","map3","res/images/cutscenes/c1j.png",15000);
	if (id == "map1")
	{
		return new Map("map1","res/conf/map1.conf");
	}
	if (id == "map2")
	{	
		return new Map("map2","res/conf/map2.conf");
	}

	if (id == "map3")
	{
        GameControl::get_instance()->set_char_position(300,400);
		return new Map("map3","res/conf/map3.conf","res/sounds/musicas/casa_inti.mp3");
	}

	if (id == "map4")
	{
		return new Map("map4","res/conf/map4.conf","res/sounds/musicas/boss.mp3");
	}

    if (id == "c2a")
        return new FrontEnd("c2a","c2b","res/images/cutscenes/c2a.png",15000);
    if (id == "c2b")
        return new FrontEnd("c2b","c2c","res/images/cutscenes/c2b.png",15000);
    if (id == "c2c")
        return new FrontEnd("c2c","title","res/images/cutscenes/c2c.png",15000);

	if (id == "credit1")
        return new FrontEnd("credit1","title","res/images/cutscenes/credit2.png",15000);

	if (id == "gameover")
	{
    	Environment *env = Environment::get_instance();
		env->camera->set_mode(Camera::STATIC);
		env->camera->set_position(0,0);
		GameControl::get_instance()->get_inti()->life()->set_life(6);
		GameControl::get_instance()->get_killa()->life()->set_life(6);
        return new FrontEnd("gameover","title","res/images/gameover/over.png");
	}
    if (id == "credit2")
        return new FrontEnd("credit2","","res/images/cutscenes/credit1.png",15000);
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

