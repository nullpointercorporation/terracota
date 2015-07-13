#include "map.h"
#include "layer.h"
#include "gamecontrol.h"
#include "dialogue_manager.h"
#include "battle_manager.h"
#include "inti.h"
#include "gameflow.h"

#include <iostream>
using namespace  std;

Map::Map(ObjectID id,const string& conf_file)
	: Level(id)
{
    GameControl* gamecontrol = GameControl::get_instance(); 
	MapManager::get_instance()->set_map(this,conf_file);
    MapManager::get_instance()->add_objects();
    MapManager::get_instance()->add_colisions();
	DialogueManager::get_instance()->set_map(this);
	DialogueManager::get_instance()->add_children(children());
	BattleManager::get_instance()->set_map(this);
	gamecontrol->set_level(this);
}

Map::~Map()
{
    GameControl* gamecontrol = GameControl::get_instance(); 
	remove_child((Object*)gamecontrol);
	DialogueManager::get_instance()->remove_children();
	BattleManager::get_instance()->remove_children();
	GameFlow::get_instance()->set_state(GameState::FRONT_END);
}

void
Map::run_physics(unsigned long elapsed)
{
    GameControl* gamecontrol = GameControl::get_instance(); 
    collision_one_to_all(gamecontrol->get_main_char(), children());    
}
	
void 
Map::next_map(const string& object)
{
	MapManager::get_instance()->next_map(object);
}
