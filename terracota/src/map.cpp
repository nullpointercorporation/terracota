#include "map.h"
#include "layer.h"
#include "gamecontrol.h"

Map::Map(ObjectID id,const string& conf_file,list<string> objects)
	: Level(id)
{
    GameControl* gamecontrol = GameControl::get_instance(); 
	gamecontrol->set_level(this);
    m_map_manager = new MapManager(this,conf_file);
    m_map_manager->add_objects(objects);
}

Map::~Map()
{
    GameControl* gamecontrol = GameControl::get_instance(); 
    remove_child(gamecontrol);
}

void
Map::run_physics(unsigned long elapsed)
{
    GameControl* gamecontrol = GameControl::get_instance(); 
    collision_one_to_all(gamecontrol->get_main_char(), children());    
}
